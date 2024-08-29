import queue

from Inference import GrammarInferencer
from DataTypes import Symbol, Prod, SymbolType
from Env import InferEnv, InferSession
from Generalize import NaiveProdGeneralizer, ProdGeneralizer
from Tool import str1


def generalize(session: InferSession, prodGeneralizer: ProdGeneralizer):
    while session.larkGen():
        prod = session.chooseLackGenProd()
        if not prodGeneralizer.generalize(session):
            session.setFindGen(prod)
    session.getEnv().update(session.getGrammar())


class IncrementalGrammarInferencer(GrammarInferencer):
    def __init__(self, env: InferEnv, balanceParen: bool = True):
        self.__env = env
        self.__balanceParen = balanceParen

    def getGrammar(self):
        env = self.__env
        npg = NaiveProdGeneralizer(True)
        while env.hasData():
            tokens = env.getTrainTokens()
            if env.getGrammarOracle().parse(tokens):
                continue
            grammar = env.getGrammar().copy()
            prod = Prod(grammar.getStart(), tuple(Symbol(token) for token in tokens))
            grammar.addProd(prod)
            inferSession = env.createSession(grammar, prod)
            generalize(inferSession, npg)
        # REP 泛化. top-down遍历clause
        grammar = env.getGrammar().copy()
        updated = True
        while updated:
            updated = False
            visited = set()
            visited.add(grammar.getStart())
            ntQ = queue.Queue()
            ntQ.put(grammar.getStart())
            session = env.createSession(grammar,None)
            while not ntQ.empty():
                nt = ntQ.get()
                for prod in grammar.getProds(nt):
                    for clause in prod.clauses():
                        if clause.isSingleNt():
                            if clause.getValueNt() not in visited:
                                ntQ.put(clause.getValueNt())
                                visited.add(clause.getValueNt())
                        context = session.getContext(clause)
                        value = context.assembly(clause.getValue()*2)
                        if session.parse(value) and not session.getGrammarOracle().parse(session.instantiate(value)):
                            updated = True
                            # REP 泛化
                            if len(clause) == 1:
                                grammar.replaceClause(clause,(Symbol(clause.getValue()[0].getValue(),SymbolType.Rep1),))
                                break
                            newProd = Prod(grammar.newNt(),clause.getValue())
                            grammar.addProd(newProd)
                            grammar.replaceClause(clause, (Symbol(newProd.getNt(), SymbolType.Rep1),))
                            break
                    if updated:
                        break
                if updated:
                    break
            env.update(grammar)
        return env.getGrammar()
