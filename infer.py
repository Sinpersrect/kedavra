# %%
# %%
import argparse
import time

from tqdm import tqdm

from Dataload import MultiFileDataLoader
from Decompose import NaiveDataDecomposer
from Env import InferEnv
from Evaluate import evaluateGrammar, TreevadaGrammarSampler, WrappedGrammar
from Inference.Inc import IncrementalGrammarInferencer
from Instantiate.Ins import DefaultTokenInstantiator, SSTokenInstantiator
from Lexical import lexicalInfer
from Lexical.Combine import MyTokenizer, combineGrammar
from Oracle.Raw import CachedRawOracle, ExternalOracle, LarkOracle
from Oracle.Tokenized import TokenizedOracle
from Tokenize.Tokenizers import DefaultTokenizer
from Consts import SEP
# 创建解析器对象
parser = argparse.ArgumentParser(description="使用oracle+示例程序推导语法")

# 添加位置参数
parser.add_argument('oracle_path', type=str, help='被测语法')
parser.add_argument('train_path', type=str, help='被测语法')
parser.add_argument('test_path', type=str, help='被测语法')
parser.add_argument('save_path', type=str, help='被测语法')
"""
oracle_path
train_path
test_path
save_path
"""
# 解析参数
args = parser.parse_args()
savePath = args.save_path
start = time.time()
def title(title: str):
    print(SEP)
    print(title)
    print(SEP)
dataLoader = MultiFileDataLoader()
rawData = dataLoader.load(args.train_path)
rawOracle = ExternalOracle(args.oracle_path)
oracle = CachedRawOracle(rawOracle)
title('Raw Data')
print('Raw data Size:', len(rawData))
totalLen = 0
for i in rawData:
    totalLen += len(i)
print('Average Length:', totalLen / len(rawData))
print('start lexical infer...')

# 词法推导
title('lexical inference')
lr = lexicalInfer(rawData, oracle)
tokenInstantiator = DefaultTokenInstantiator()
if not lr.spaceSensitive:
    tokenInstantiator = SSTokenInstantiator()
totalLen = 0
for i in lr.data:
    totalLen += len(i)
print('Average Token Length:', totalLen / len(lr.data))
tokenizedOracle = TokenizedOracle(oracle, tokenInstantiator)
tokenizedData = lr.data

# 数据分解
title('data decompose')
print('start data decompose...')
decData = set()
ndd = NaiveDataDecomposer(tokenizedOracle)
for tokens in tqdm(tokenizedData):
    decData = decData.union(ndd.decompose(tokens))
decData = list(sorted(decData, key=len))
totalLen = 0
for i in decData:
    totalLen += len(i)
print('decomposed size:', len(decData))
print('average token length:', totalLen / len(decData))
print()

# 语法推导
env = InferEnv(tokenizedOracle, decData)
title('incremental grammar inference')
inferencer = IncrementalGrammarInferencer(env)
inferencer.getGrammar()
grammar = env.getGrammar()
file = open(savePath, mode='w')
print(grammar)
print(grammar, file=file)
total = time.time() - start
print('total time:', time.time() - start)
print('total time:', time.time() - start, file=file)
print({'call': oracle.calls, 'call_time': oracle.callTime}, file=file)
file.close()

# 合并词法和语法
lexicalDict = lr.lexicalDict
spaceSensitive = lr.spaceSensitive
mt = MyTokenizer(lr.lexicalDict, lr.spaceSensitive)
grammar = combineGrammar(env.getGrammar(), lr.lexicalDict)
larkStr = str(grammar)
if not lr.spaceSensitive:
    larkStr = larkStr + '\n' + r'%ignore /\s+/'
tokenizer = mt


sampler = TreevadaGrammarSampler(env.getGrammar(), tokenizer)
wg = WrappedGrammar(grammar, sampler, LarkOracle(larkStr))
"""
生成的结果为三元组：
语法,词法,SpaceSensitive
"""
with open(savePath + '.gramdict', mode='w') as f:
    print(repr({'grammar': env.getGrammar(), 'lexicalDict': lexicalDict, 'spaceSensitive': spaceSensitive}),
          file=f)
print(evaluateGrammar(wg, dataLoader.load(args.test_path),
                      {'infer_time': total, 'oracle_time': oracle.callTime, 'calls': oracle.calls},
                      rawOracle,
                      savePath + '.eval'))

# python3 infer.py ./Benchmark/lisp/parse_lisp ./Benchmark/lisp/lisp-train-ase21-h ./Benchmark/lisp/lisp-test lisp-r0