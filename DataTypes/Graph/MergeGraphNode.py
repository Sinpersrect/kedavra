from DataTypes.Graph import DirectedGraph
from DataTypes.__DisjointSet import DisjointSet


class GraphNodeMerger:
    def __init__(self, graph: DirectedGraph):
        self.__graph = graph
        self.__disjointSet = DisjointSet()
        self.__newGraph = None
        # 把所有节点放入并查集，后续需要用到
        for node in self.__graph.getNodes():
            self.__disjointSet.getParent(node)
        # 旧图到新图的映射
        self.__old2new = {}
        # 新图到旧图的映射
        self.__new2old = {}

    def merge(self, node1, node2) -> None:
        """
        合并点
        :param node1:
        :param node2:
        :return:
        """
        if self.__newGraph is not None:
            self.__old2new = {}
            self.__new2old = {}
            self.__newGraph = None
        self.__disjointSet.merge(node1, node2)

    def getMergedGraph(self) -> DirectedGraph:
        if self.__newGraph is not None:
            return self.__newGraph
        self.__newGraph = DirectedGraph()
        # 构造新图的点集
        self.__new2old = [set(i) for i in self.__disjointSet.getSets()]  # 合并之后的点
        self.__old2new = {}
        for i, oldNodes in enumerate(self.__new2old):
            self.__newGraph.addNode(i)
            for oldNode in oldNodes:
                self.__old2new[oldNode] = i
        # 构造边
        for i, oldNodes in enumerate(self.__new2old):
            for oldNode in oldNodes:
                for oldNbr in self.__graph.getNbrs(oldNode):
                    # 保留自环性质
                    if oldNbr == oldNode and not self.__newGraph.findEdge(i, i):
                        self.__newGraph.addEdge(i, i)
                        continue
                    # 普通边
                    newNbr = self.old2new(oldNbr)
                    if newNbr != i and not self.__newGraph.findEdge(i, newNbr):
                        self.__newGraph.addEdge(i, newNbr)
        return self.__newGraph

    def old2new(self, node):
        if self.__newGraph is None:
            return None
        return self.__old2new[node]

    def new2old(self, node):
        if self.__newGraph is None:
            return None
        return self.__new2old[node]
