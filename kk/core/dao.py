# Container for storing data between parts of the program

class Dao:
    def __init__(self, data):
        self.data = data
        self.awake = True
        self.currentplace = 0

    def get_data(self, dataname):
        if dataname in self.data:
            return self.data[dataname]
        else:
            return None
    
    def set_data(self, dataname, data):
        self.data[dataname] = data
    
    def check_beats(self, outman):
        beats = self.get_data("beats")
        if beats is not None:
            for beat in beats:
                if beat.met_condition(self):
                    beat.execute(outman, self)
    
    def get_current_place(self):
        places = list(self.get_data("places"))
        if places is not None:
            return places[self.currentplace]
        else:
            return None

    def move(self, to):
        self.currentplace = to
        self.get_current_place().get_description()

    def turn_off(self):
        self.awake = False
    def is_awake(self):
        return self.awake
