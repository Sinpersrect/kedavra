import time
from abc import abstractmethod
import os
import subprocess
import tempfile

import lark

from Statistics import counter


class RawOracle:
    @abstractmethod
    def parse(self, sentence: str) -> bool:
        pass


class ExternalOracle(RawOracle):
    def __init__(self, command):
        """
        该oracle的输入必须是字符串。
        `command` is a string representing the oracle command, i.e. `command` = "readpng"
        in the oracle call:
            $ readpng <MY_FILE>
        """
        self.command = command

    def parse(self, sentence: str) -> bool:
        return self.__parse_internal(sentence)

    def __parse_internal(self, string):
        """
        Does the work of calling the subprocess.
        """
        # print(string)
        FNULL = open(os.devnull, 'w')
        f = tempfile.NamedTemporaryFile()
        f.write(bytes(string, 'utf-8'))
        f_name = f.name
        f.flush()
        try:
            # With check = True, throws a CalledProcessError if the exit code is non-zero
            command = ''
            if self.command.endswith('.sh'):
                command = 'bash'
            elif self.command.endswith('.py'):
                command = 'python3'
            commands = [command, self.command, f_name]
            if commands[0] == '':
                commands = commands[1:]
            subprocess.run(commands, stdout=FNULL, stderr=FNULL, check=True, timeout=10)
            f.close()
            FNULL.close()
            return True
        except subprocess.CalledProcessError as e:
            f.close()
            FNULL.close()
            return False
        except subprocess.TimeoutExpired as e:
            print(f"Caused timeout: {string}")
            f.close()
            FNULL.close()
            return True


class CachedRawOracle(RawOracle):
    def __init__(self, oracle: RawOracle):
        self.__oracle = oracle
        self.__cache = {}
        self.calls = 0
        self.callTime = 0

    def parse(self, sentence: str) -> bool:
        if sentence not in self.__cache:
            self.calls += 1
            start = time.time()
            self.__cache[sentence] = self.__oracle.parse(sentence)
            self.callTime += time.time() - start
        return self.__cache[sentence]


class LarkOracle(RawOracle):
    def __init__(self, larkStr) -> None:
        self.__parser = lark.Lark(larkStr)

    @counter('LarkOracle')
    def parse(self, sentence) -> bool:
        try:
            self.__parser.parse(sentence)
            return True
        except:
            return False
