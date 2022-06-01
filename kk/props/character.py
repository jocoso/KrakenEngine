from .object import Object

class Character(Object):
    def __init__(self, name, description):
        Object.__init__(self, name, description)
        self.attributes = dict()
    
    def set_attribute(self, attributename:str, val):
        self.attributes[attributename] = val
    def get_attribute(self, attributename:str):
        if attributename in self.attributes:
            return self.attributes[attributename]