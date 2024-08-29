from typing import Hashable, Set, Tuple, Collection


class DisjointSet:
    def __init__(self,clusters:Collection[Collection]=None) -> None:
        self.__parent = dict()
        if clusters is not None:
            for cluster in clusters:
                iterator = iter(cluster)
                firstItem = next(iterator)
                self.getParent(firstItem)
                for remainItem in iterator:
                    self.merge(firstItem,remainItem)

    def getParent(self, x: Hashable):
        if x not in self.__parent:
            self.__parent[x] = x
            return x
        if self.__parent[x] == x:
            return x
        self.__parent[x] = self.getParent(self.__parent[x])
        return self.__parent[x]

    def merge(self, x: Hashable, y: Hashable) -> Hashable:
        self.__parent[self.getParent(y)] = self.getParent(x)
        return x

    def getSets(self) -> Set[frozenset]:
        ret = {}
        for i in self.__parent:
            if self.getParent(i) not in ret:
                ret[self.getParent(i)] = []
            ret[self.getParent(i)].append(i)
        return {frozenset(i) for i in ret.values()}
