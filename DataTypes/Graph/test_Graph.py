from typing import Set, Tuple

import pytest

from DataTypes.Graph.MergeGraphNode import GraphNodeMerger

from DataTypes.Graph.__DirectedGraph import DirectedGraph
from DataTypes.Graph.__UndirectedGraph import UndirectedGraph


def testGraph_ElementalOperation():
    # 检测addNode和removeNode是否工作正常
    g = DirectedGraph()
    assert not g.findNode("0")
    g.addNode("0")
    with pytest.raises(Exception):
        g.addNode("0")
    assert g.findNode("0")
    g.removeNode("0")
    with pytest.raises(Exception):
        g.removeNode("0")
    assert not g.findNode("0")
    # 检测getNodes
    g = DirectedGraph()
    g.addNode("1")
    g.addNode("2")
    assert set(g.getNodes()) == {"1", "2"}
    # 检测边的添加和删除是否正常
    g = DirectedGraph()
    g.addNode("1")
    g.addNode("2")
    g.addEdge("1", "2")
    with pytest.raises(Exception):
        g.addEdge("1", "2")
    with pytest.raises(Exception):
        g.getNbrs("3")
    assert g.findEdge("1", "2")
    assert not g.findEdge("2", "1")
    assert set(g.getNbrs("1")) == {"2"}
    assert set(g.getNbrs("2")) == set()
    g.removeEdge("1", "2")
    with pytest.raises(Exception):
        g.removeEdge("1", "2")
    assert set(g.getNbrs("1")) == set()
    g.addEdge("1", "2")
    g.removeNode("2")
    assert set(g.getNbrs("1")) == set()


def getDAG1() -> DirectedGraph:
    g = DirectedGraph()
    for i in range(5):
        g.addNode(str(i))
    for i in range(4):
        g.addEdge(str(i), str(i + 1))
    return g


def getDAG2() -> DirectedGraph:
    g = DirectedGraph()
    for i in range(5):
        g.addNode(str(i))
    g.addEdge("0", "1")
    g.addEdge("0", "2")
    g.addEdge("2", "3")
    g.addEdge("2", "4")
    return g


def getDAG3() -> DirectedGraph:
    g = DirectedGraph()
    for i in range(5):
        g.addNode(str(i))
    g.addEdge("0", "1")
    g.addEdge("0", "2")
    g.addEdge("3", "4")
    return g


def getLoopGraph1() -> DirectedGraph:
    g = DirectedGraph()
    for i in range(5):
        g.addNode(str(i))
    for i in range(5):
        g.addEdge(str(i), str((i + 1) % 5))
    return g


def getLoopGraph2() -> DirectedGraph:
    g = DirectedGraph()
    for i in range(5):
        g.addNode(str(i))
    g.addEdge("0", "1")
    g.addEdge("0", "2")
    g.addEdge("3", "4")
    g.addEdge("4", "3")
    return g


def testGraph_ContainsLoop():
    for g in [getDAG1(), getDAG2(), getDAG3()]:
        assert not g.isCyclic()
    for g in [getLoopGraph1(), getLoopGraph2()]:
        assert g.isCyclic()


def test_FindPath():
    g = getDAG2()
    path = g.findPath('0', '4')
    edges = path.getEdges()
    assert next(edges) == ('0', '2')
    assert next(edges) == ('2', '4')


def test_GetReachableNodesCyclic():
    # Case 1
    g = getLoopGraph2()
    """
    0 -> 1
    0 -> 2
    3 -> 4
    4 -> 3
    """
    assert g.getReachableNodes('0') == {'1', '2'}
    assert g.getReachableNodes('1') == set()
    assert g.getReachableNodes('2') == set()
    assert g.getReachableNodes('3') == {'3', '4'}
    assert g.getReachableNodes('4') == {'3', '4'}


def test_GetReachableNodesCyclic2():
    # Case 1
    g = DirectedGraph()
    for i in range(1):
        g.addNode(str(i))
    g.addEdge("0", "0")
    """
    0 -> 0
    """
    assert g.getReachableNodes('0') == {'0'}


def test_GetReachableNodesAcyclic():
    # Case 1
    g = getDAG2()
    """
    0 -> 1
    0 -> 2
    2 -> 3
    2 -> 4
    """
    assert g.getReachableNodes('0') == {'1', '2', '3', '4'}
    assert g.getReachableNodes('1') == set()
    assert g.getReachableNodes('2') == {'3', '4'}

    # Case 3
    g = getDAG1()
    """
    0 -> 1
    1 -> 2
    2 -> 3
    3 -> 4
    """
    assert g.getReachableNodes('0') == {'1', '2', '3', '4'}
    assert g.getReachableNodes('1') == {'2', '3', '4'}
    assert g.getReachableNodes('2') == {'4', '3'}
    assert g.getReachableNodes('3') == {'4'}
    assert g.getReachableNodes('4') == set()


def assertCliques(g: UndirectedGraph, cliques: Set[Tuple]):
    assert {tuple(sorted(i)) for i in g.getMaximalCliques()} == cliques


def test_GetMaximalCliques():
    # Case1 Simple Graph
    g = UndirectedGraph()
    for i in range(4):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    g.addEdge(3, 1)
    assertCliques(g, {(0, 1), (1, 2, 3)})
    # Case2 Complex Graph
    g = UndirectedGraph()
    for i in range(6):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(1, 3)
    g.addEdge(1, 4)
    g.addEdge(2, 4)
    g.addEdge(2, 5)
    g.addEdge(3, 4)
    g.addEdge(4, 5)
    assertCliques(g, {(0, 1, 2), (1, 3, 4), (1, 2, 4), (2, 4, 5)})


def test_direct2undirected():
    g = DirectedGraph()
    for i in range(4):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    assert not g.findEdge(1, 0)
    assert not g.findEdge(2, 1)
    assert not g.findEdge(3, 2)
    g = UndirectedGraph.fromDirectGraph(g)
    assert g.findEdge(1, 0)
    assert g.findEdge(2, 1)
    assert g.findEdge(3, 2)


def test_mergeNode():
    # Case1 不包含自环
    g = DirectedGraph()
    for i in range(4):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    merger = GraphNodeMerger(g)
    merger.merge(0, 1)
    g1 = merger.getMergedGraph()
    assert merger.old2new(0) == merger.old2new(1)
    assert g1.findEdge(merger.old2new(0), merger.old2new(2))
    assert merger.new2old(merger.old2new(0)) == {0, 1}
    # Case2 包含自环
    g = DirectedGraph()
    for i in range(4):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(0, 0)
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    merger = GraphNodeMerger(g)
    merger.merge(0, 1)
    g1 = merger.getMergedGraph()
    assert merger.old2new(0) == merger.old2new(1)
    assert g1.findEdge(merger.old2new(0), merger.old2new(2))
    assert g1.findEdge(merger.old2new(0), merger.old2new(0))


def assertSCCs(graph: UndirectedGraph, sccs: Set[Tuple]):
    actualSccs = graph.getStronglyConnectedComponents()
    assert actualSccs == {frozenset(i) for i in sccs}


def test_UndirectedGraphSCCs():
    # Case1 Simple Graph
    g = UndirectedGraph()
    for i in range(4):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    g.addEdge(3, 1)
    assertSCCs(g, {(0, 1, 2, 3)})
    # Case2 Complex Graph
    g = UndirectedGraph()
    for i in range(6):
        g.addNode(i)
    g.addEdge(0, 1)
    g.addEdge(1, 2)
    g.addEdge(3, 4)
    g.addEdge(3, 5)
    assertSCCs(g, {(0, 1, 2), (3, 4, 5)})

def test_GraphRemove():
    g = UndirectedGraph()
    g.addNode(0)
    g.addNode(1)
    g.addEdge(0,1)
    g.removeNode(0)
    assert len(g.getNbrs(1))==0