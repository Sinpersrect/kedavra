import itertools
from typing import FrozenSet, Set

from DataTypes.Graph.MergeGraphNode import GraphNodeMerger
from DataTypes.Graph.__DirectedGraph import DirectedGraph


class UndirectedGraph(DirectedGraph):
    def addEdge(self, src, dst, forced=False) -> None:
        super().addEdge(src, dst, forced)
        if src != dst:
            super().addEdge(dst, src, forced)

    @staticmethod
    def fromDirectGraph(directGraph: DirectedGraph) -> "UndirectedGraph":
        ug = UndirectedGraph()
        for node in directGraph.getNodes():
            ug.addNode(node)
        for node in directGraph.getNodes():
            for nbr in directGraph.getNbrs(node):
                if ug.findEdge(node, nbr):
                    continue
                ug.addEdge(node, nbr)
        return ug

    def getStronglyConnectedComponents(self) -> Set[FrozenSet]:
        """
        获取无向图的强联通分量
        :return: 强联通分量
        """
        visited = set()
        scc = set()
        sccs = set()

        def dfs(current):
            if current in visited:
                return
            scc.add(current)
            visited.add(current)
            for nbr in self.getNbrs(current):
                dfs(nbr)

        for node in self.getNodes():
            if node in visited:
                continue
            dfs(node)
            sccs.add(frozenset(scc))
            scc = set()
        return sccs

    def __getMaximalCliquesContracted(self) -> Set[FrozenSet]:
        merger = GraphNodeMerger(self)
        for node in self.getNodes():
            for nbr in self.getNbrs(node):
                if set(self.getNbrs(node)).union({node}) == set(self.getNbrs(nbr)).union({nbr}):
                    merger.merge(node,nbr)
        contractedGraph = merger.getMergedGraph()
        contractedCliques = UndirectedGraph.fromDirectGraph(contractedGraph).getMaximalCliques()
        originalCliques = set()
        for contractedClique in contractedCliques:
            clique = set()
            for node in contractedClique:
                clique = clique.union(merger.new2old(node))
            originalCliques.add(frozenset(clique))
        return originalCliques

    def getMaximalCliques(self, nodeContract: bool = False) -> Set[FrozenSet]:
        """
        获取所有极大团，Maximal是极大，Maximum是最大。
        时间复杂度为3^(n/3)，这是一个NP Complete问题
        :type nodeContract: 是否缩点，有些情况下，缩点可以大幅度提高效率
        :return:
        """
        """
        R := {}
        P := node set of G 
        X := {}

        BronKerbosch(R, P, X):
            if P and X are both empty:
                report R as a maximal clique
            for each vertex v in P:
                BronKerbosch(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
                P := P - {v}
                X := X ⋃ {v}
        """
        if nodeContract:
            return self.__getMaximalCliquesContracted()
        R, P, X = set(), set(self.getNodes()), set()
        maximalCliques = list()

        # TODO 后续可以考虑把递归改为迭代，优化效率
        def bronKerbosch(r: Set, p: Set, x: Set):
            if len(p) == 0 and len(x) == 0:
                maximalCliques.append(tuple(r))
            toVisited = set(p)
            for node in toVisited:
                nbrs = set(self.getNbrs(node))
                bronKerbosch(r.union({node}), p.intersection(nbrs), x.intersection(nbrs))
                p.remove(node)
                x.add(node)

        bronKerbosch(R, P, X)
        return {frozenset(clique) for clique in maximalCliques}

    def getMISs(self):
        # 构建一个补图
        complement = UndirectedGraph()
        for node in self.getNodes():
            complement.addNode(node)
        for node1,node2 in itertools.combinations(self.getNodes(), 2):
            if not self.findEdge(node1,node2):
                complement.addEdge(node1,node2)
        return complement.getMaximalCliques()
