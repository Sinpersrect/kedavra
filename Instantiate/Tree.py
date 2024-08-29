from typing import List, Optional, Tuple
from DataTypes import Prod,Symbol
from Tokenize import Token
from colored import bg,attr
TAB = '  '
class SyntaxNode:
    def __init__(self,symbol:Symbol,prod:Prod=None) -> None:
        assert symbol is not None
        self._symbol = symbol
        self._prod = prod
        if prod is not None:
            assert not self._symbol.isTerminal() and self._symbol.getValue() == self._prod.getNt()
        self._subNodes = [SyntaxNode(symbol) for symbol in prod] if prod is not None else []
    
    def getProd(self):
        return self._prod
    
    def getSymbol(self):
        return self._symbol
    
    def isTerminal(self):
        return self._symbol.isTerminal()
    
    def __eq__(self, value: object) -> bool:
        return str(self)==str(value)
    
    def __hash__(self) -> int:
        return hash(str(self))

    def __str__(self) -> str:
        if self.getProd() is None:
            if not self._symbol.isTerminal():
                return bg('blue') + str(self._symbol) + attr('reset')
            return str(self._symbol)
        ret = [bg('blue') + self._prod.getNt()+ attr('reset')+':']
        for subNode in self._subNodes:
            ret.append('\n'.join([TAB+i for i in str(subNode).split('\n')]))
        return '\n'.join(ret)
    
    def produce(self,prod:Prod):
        assert self._prod is None
        self._prod = prod
        self._subNodes = [SyntaxNode(symbol) for symbol in prod]

    def getChildren(self)->List["SyntaxNode"]:
        return self._subNodes
    
    def setChildren(self,children:List["SyntaxNode"]):
        self._subNodes = children

    def copy(self):
        import copy
        ret = SyntaxNode(self.getSymbol(),self.getProd())
        ret._subNodes = copy.deepcopy(self._subNodes)
        return ret

    def __toTokens(self)->List[Token]:
        if self.isTerminal():
            return [self.getSymbol().getValue()]
        if self._prod is None:
            raise Exception("Not Complete Syntax Tree")
        ret = []
        for i,symbol in enumerate(self._prod):
            if symbol.isTerminal():
                ret.append(symbol.getValue())
            else:
                ret += self.getChildren()[i].__toTokens()
        return ret

    def toTokens(self)->Tuple[Token]:
        return tuple(self.__toTokens())
    
class StaticSyntaxNode(SyntaxNode):
    def __init__(self, sn:SyntaxNode) -> None:
        super().__init__(sn.getSymbol(), sn.getProd())
        self._subNodes = tuple(StaticSyntaxNode(i) for i in sn._subNodes)
        self._str = None

    def __str__(self) -> str:
        if self._str is not None:
            return self._str
        if self.getProd() is None:
            if not self._symbol.isTerminal():
                self._str = bg('blue') + str(self._symbol) + attr('reset')
                return self._str
            self._str = str(self._symbol)
            return self._str
        ret = [bg('blue') + self._prod.getNt()+ attr('reset')+':']
        for subNode in self._subNodes:
            ret.append('\n'.join([TAB+i for i in str(subNode).split('\n')]))
        self._str = '\n'.join(ret)
        return self._str
    
    def produce(self,prod:Prod):
        raise Exception('Static Syntax Node is Not Producable')

    def getChildren(self)->List["SyntaxNode"]:
        return list(self._subNodes)

    def copy(self):
        import copy
        ret = StaticSyntaxNode(self.getSymbol(),self.getProd())
        ret._subNodes = copy.deepcopy(self._subNodes)
        return ret

class SyntaxTree:
    def __init__(self,root:Optional[SyntaxNode]=None) -> None:
        self.__root = root

    def getRoot(self):
        return self.__root
    
    def setRoot(self,root:SyntaxNode):
        self.__root = root

    def __str__(self) -> str:
        return str(self.getRoot())
    
    def toTokens(self):
        return self.__root.toTokens()