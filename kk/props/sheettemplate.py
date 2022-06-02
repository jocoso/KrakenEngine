from abc import ABC, abstractmethod

from .character import Character
from ..core.outputmanager import OutputManager
from ..core.dao import Dao

class SheetTemplate(ABC):
    def __init__(self, attr:dict = None):
        self.attr = dict() if attr == None else attr

    def get_player(self):
        player = Character(None, None)
        for key in self.attr:
            player.set_attribute({key: self.attr[key]})
        return player

    @abstractmethod
    def write(self, outman: OutputManager, dao:Dao):
        pass