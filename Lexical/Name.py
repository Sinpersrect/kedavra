class NameAllocator:
    def __init__(self, prefix='t'):
        self.__index = 0
        self.__prefix = prefix

    def name(self):
        ret = "%s%d" % (self.__prefix, self.__index)
        self.__index += 1
        return ret
