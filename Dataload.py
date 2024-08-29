from abc import abstractmethod
import os
from typing import Collection


class DataLoader:
    @abstractmethod
    def load(self, path) -> Collection[str]:
        pass


class MultiFileDataLoader(DataLoader):
    def load(self, path) -> Collection[str]:
        if not os.path.exists(path):
            return []
        data = []
        for filename in os.listdir(path):
            filePath = os.path.join(path, filename)
            if not os.path.isfile(filePath):
                continue
            file = open(filePath)
            data.append(file.read())
            file.close()
        return data


class SingleLineDataLoader(DataLoader):
    def load(self, path) -> Collection[str]:
        if not os.path.exists(path):
            return []
        return open(path).read().split('\n')