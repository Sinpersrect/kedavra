import queue
from typing import List, Generator, Hashable, Set, Tuple, Dict, TypeVar



class Path:
    def __init__(self, nodeSeq: List):
        self.__nodeSeq = nodeSeq

    def getEdges(self) -> Generator:
        for i in range(len(self.__nodeSeq) - 1):
            yield self.__nodeSeq[i], self.__nodeSeq[i + 1]

    def __len__(self):
        return max(len(self.__nodeSeq) - 1, 0)


T = TypeVar("T", bound=Hashable)


class DirectedGraph:
    def __init__(self):
        self.__graph = {}
        self.__reachableSet = None

    def addNode(self, node: T) -> None:
        """
        添加节点，如果节点已存在，则报错
        :param node: 节点名
        :return: None
        """
        if self.findNode(node):
            raise Exception(node, '该节点已经存在，不能重复添加')
        self.__reachableSet = None
        self.__graph[node] = set()

    def removeNode(self, node: T) -> None:
        """
        删除节点，如果节点不存在，则报错
        :param node: 节点名
        :return: None
        """
        if not self.findNode(node):
            raise Exception(node)
        self.__reachableSet = None
        self.__graph.pop(node)

    def findNode(self, node: T) -> bool:
        """
        判断节点是否存在
        :param node: 节点名
        :return: 是否存在
        """
        return node in self.__graph

    def getNodes(self) -> List[T]:
        """
        获取图中的所有节点
        :return: 所有节点
        """
        return list(self.__graph.keys())

    def addEdge(self, src, dst, forced=False) -> None:
        """
        添加一个新边，如果其中一个节点不存在，或者边已存在，则报错
        :param src:起点
        :param dst:终点
        :param forced: 是否强制添加，若为True，则在节点不存在时新增节点
        :return:None
        """
        if not self.findNode(src):
            if not forced:
                raise Exception(src, dst, "起点不存在")
            else:
                self.addNode(src)
        if not self.findNode(dst):
            if not forced:
                raise Exception(src, dst, "终点不存在")
            else:
                self.addNode(dst)
        if self.findEdge(src, dst) and not forced:
            raise Exception(src, dst, "该边已存在，不能重复添加")
        self.__reachableSet = None
        self.__graph[src].add(dst)

    def getNbrs(self, node: T) -> Set[T]:
        """
        获取当前节点在图中的后继节点，如果节点不存在，报错
        :param node: 节点名
        :return: 节点列表
        """
        if not self.findNode(node):
            raise Exception(node)
        # TODO 这里会带来大量的开销，优化？
        nbrs = {nbr for nbr in self.__graph[node] if self.findNode(nbr)}
        if len(nbrs) != len(self.__graph[node]):
            self.__graph[node] = set(nbrs)
        return nbrs

    def removeEdge(self, src, dst) -> None:
        """
        从图中删除一个边，如果边不存在，则报错
        :param src:起点
        :param dst:终点
        :return:None
        """
        if not self.findEdge(src, dst):
            raise Exception(src, dst, '该边不存在，无法删除')
        self.__reachableSet = None
        self.__graph[src].remove(dst)

    def findEdge(self, src, dst) -> bool:
        """
        判断边是否存在
        :param src:起点
        :param dst: 终点
        :return: 是否存在
        """
        return self.findNode(src) and dst in self.__graph[src]

    def isCyclic(self) -> bool:
        """
        判断图中是否包含环。
        :return:
        """
        # 针对每一个没有访问过的节点使用bfs，然后判断是否访问到自己
        for node in self.getNodes():
            # bfs
            visited = {node}
            q = queue.Queue()
            q.put(node)
            while not q.empty():
                for nbr in self.getNbrs(q.get()):
                    if nbr == node:
                        return True
                    if nbr in visited:
                        continue
                    visited.add(nbr)
                    q.put(nbr)
        return False

    def findPath(self, startNode: T, destNode: T) -> Path:
        q = queue.Queue()
        q.put(startNode)
        previousNodeRecord = {}
        visitedNode = {startNode}
        # 使用bfs搜索来找最短路径
        while not q.empty():
            node = q.get()
            breakFlag = False
            for nextNode in self.getNbrs(node):
                if nextNode in visitedNode:
                    continue
                visitedNode.add(nextNode)
                q.put(nextNode)
                previousNodeRecord[nextNode] = node
                if nextNode == destNode:
                    breakFlag = True
                    break
            if breakFlag:
                break
        # 重构path
        currentNode = destNode
        nodeSeq = []
        while currentNode is not startNode:
            nodeSeq.append(currentNode)
            currentNode = previousNodeRecord[currentNode]
        nodeSeq.append(startNode)
        return Path(list(reversed(nodeSeq)))

    def __initReachableSet(self):
        """
        初始化可达集
        算法步骤：
        DAG：dfs
        DCG：tarjan + dfs
        :return:
        """
        if not self.isCyclic():
            self.__initAcyclicGraphReachableSet()
            return
        # 缩点
        acyclicGraph, nodeMap, nodeMapInv = self.shrinkSCC()
        # 计算可达集
        self.__reachableSet = {}
        for oldNode in self.getNodes():
            self.__reachableSet[oldNode] = set()
            newNode = nodeMapInv[oldNode]  # 映射到缩点的图中
            # 获取缩点图的可达集
            for reachableNewNode in acyclicGraph.getReachableNodes(newNode):
                self.__reachableSet[oldNode] = self.__reachableSet[oldNode].union(nodeMap[reachableNewNode])
            if len(nodeMap[newNode]) > 1:
                self.__reachableSet[oldNode] = self.__reachableSet[oldNode].union(nodeMap[newNode])
            # 自环检测
            if self.findEdge(oldNode, oldNode):
                self.__reachableSet[oldNode].add(oldNode)

    def __initAcyclicGraphReachableSet(self):
        """
        初始化无环图的可达集
        :return:
        """
        self.__reachableSet = {}
        # 构造反向图，使用dfs计算可达集
        invGraph = DirectedGraph()
        for node in self.getNodes():
            invGraph.addNode(node)
            self.__reachableSet[node] = set()
        for node in self.getNodes():
            for nbr in self.getNbrs(node):
                invGraph.addEdge(nbr, node)

        # 使用dfs计算可达集，这里采用递归的方法
        def dfs(currentNode: T, prevNodes: Set[T]):
            for nbrNode in invGraph.getNbrs(currentNode):
                prevNodes.add(currentNode)
                self.__reachableSet[nbrNode] = self.__reachableSet[nbrNode].union(prevNodes)
                dfs(nbrNode, prevNodes)
                prevNodes.remove(currentNode)

        # 针对所有起点执行dfs
        for node in invGraph.getNodes():
            # 非起点，跳过
            if len(self.getNbrs(node)) != 0:
                continue
            dfs(node, set())

    def getReachableNodes(self, node: T) -> Set:
        if self.__reachableSet is None:
            self.__initReachableSet()
        return self.__reachableSet[node]

    def shrinkSCC(self) -> Tuple["DirectedGraph", Dict, Dict]:
        """
        把有向图当中的强联通分量缩为一点
        :return:缩点后的有向图,缩点后的图节点到之前的映射
        """
        """
        tarjan算法
        这里我们用 dfn[i] 表示编号为 i 的节点在 dfs 的过程中的遍历顺序，就是一个 dfs 序。（也可以叫时间戳）
        用 low[i] 表示 i 节点及其下方节点所能到达的开始时间最早的节点的开始时间。（初始时 low[i] = dfn[i]）
        这里有 1 个性质：因为在 dfs 的过程中会形成一棵搜索树，所以在越上面的节点显然 dfn 就会越小。
        如果发现一个点有边连到了搜索树中的自己的祖宗节点，那么就更新其low的值。
        1、如果一个节点的 low 值小于 dfn 值，那么就说明它或者它的子孙节点有边连到自己上方的节点。
        2、如果一个节点的 low 值等于 dfn 值，则说明其下方的节点不能走到其上方节点，那么该节点就是一个强连通分量在搜索树中的根。
        3、但是 u 的子孙节点就未必和 u 处于同一个强连通分量，用栈存储即可
        """
        dfn = {}
        low = {}
        nodeStack = []
        stackSet = set()
        sccs = []

        def dfs(currentNode: T, ts):
            if currentNode in dfn:
                return ts
            dfn[currentNode] = ts
            low[currentNode] = ts
            nodeStack.append(currentNode)
            stackSet.add(currentNode)
            ts += 1
            for nbrNode in self.getNbrs(currentNode):
                if nbrNode not in dfn:
                    ts = dfs(nbrNode, ts)
                    low[currentNode] = min(low[nbrNode], low[currentNode])
                elif nbrNode in stackSet:
                    low[currentNode] = min(low[nbrNode], low[currentNode])
            # 说明node是一个强联通分量的根
            if dfn[currentNode] == low[currentNode]:
                scc = set()
                while True:
                    stackNode = nodeStack.pop()
                    scc.add(stackNode)
                    stackSet.remove(stackNode)
                    if stackNode == currentNode:
                        break
                sccs.append(scc)
            return ts

        count = 0
        # 遍历所有节点执行tarjan算法
        for node in self.getNodes():
            if node in dfn:
                continue
            count = dfs(node, count)
        # print(sccs)
        # 构造缩点图
        newGraph = DirectedGraph()
        for i in range(len(sccs)):
            newGraph.addNode(i)
        # 构造新图和旧图节点的双向映射
        nodeMap = {i: sccs[i] for i in range(len(sccs))}
        nodeMapInv = {}
        for newNode in nodeMap.keys():
            for oldNode in nodeMap[newNode]:
                nodeMapInv[oldNode] = newNode
        # 构造缩点图映射
        for node in self.getNodes():
            for nbr in self.getNbrs(node):
                if nodeMapInv[node] == nodeMapInv[nbr]:
                    continue
                newNode1 = nodeMapInv[node]
                newNode2 = nodeMapInv[nbr]
                if newGraph.findEdge(newNode1, newNode2):
                    continue
                newGraph.addEdge(newNode1, newNode2)
        return newGraph, nodeMap, nodeMapInv


if __name__ == '__main__':
    g = DirectedGraph()
    for i in range(5):
        g.addNode(str(i))
    g.addEdge("0", "1")
    g.addEdge("0", "2")
    g.addEdge("2", "0")
    g.addEdge("3", "4")
    g.addEdge("4", "3")
    g.shrinkSCC()
