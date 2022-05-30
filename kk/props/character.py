from .object import Object

class Character(Object):
    def __init__(self, name, description):
        Object.__init__(self, name, description)