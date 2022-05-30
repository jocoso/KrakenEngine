from .object import Object

class Place(Object):
    def __init__(self, name, description, adjacentplaces = None):
        Object.__init__(self, name, description)
        self.objects = dict()
        self.adjacentplaces = [None, None, None, None]

        if adjacentplaces is not None:
            self.add_adjacent(adjacentplaces)
        
        self.coordinates = {
            'north': 0,
            'east': 1,
            'south': 2,
            'west': 3,
        }


    def add_to_place(self, objectname, object):
        if objectname not in self.objects:
            self.objects[objectname] = object
        else:
            raise ValueError("The object you tried to add to Place " + self.name + " already exists")

    def find_in_place(self, objectname):
        if objectname in self.objects:
            return self.objects[objectname]
        return None

    def get_description(self):
        desc = "<" + self.name + ">\n" + self.description + "\n"
        if self.objects:
            desc += "In the place you can see:\n"
            for objectname in self.objects:
                desc += "-" + objectname + "\n"
        return desc
    
    def get_adjacent(self, coordinate):
        index = self.coordinates.get(coordinate, -1)

        return self.adjacentplaces[index] if index > 0 else None

    def add_adjacent(self, data):
        if(isinstance(data, list)): 
            self.adjlist(data)
        elif(isinstance(data, dict)):
            self.adjdict(data)
        else:
            raise Exception("Input should be type list or dict, not type ", type(data) )

    def adjlist(self, data):
        max = -1

        if len(data) <= 4:
            max = len(data)
        else:
            max = 4
        
        for i in range(max):
            self.adjacentplaces[i] = data[i]
    
    def adjdict(self, data):
        for key in data.keys():
            coord = self.coordinates.get(data[key], -1)
            if coord > 0:
                self.adjacentplaces[coord] = data[key]

