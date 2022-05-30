from abc import ABC, abstractmethod

class Verb(ABC):
    @abstractmethod
    def do(self, userinput, dao):
        pass