from abc import ABC, abstractmethod

# A game event. 
# If condition is met, the beat can be safetly executed

class Beat(ABC):
    @abstractmethod
    def met_condition(self, dao):
        pass
    @abstractmethod
    def execute(self, outman, dao):
        pass