from abc import ABC

class Object(ABC):
    def __init__(self, name, description):
        self.name = name
        self.description = description

    def get_name(self):
        return self.name
    def get_description(self):
        return self.description
    def set_name(self, name):   
        self.name = name
    def set_description(self, description):
        self.description = description