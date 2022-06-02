
class Wiki:
    def __init__(self, data = None):
        self.data = dict() if data == None else data

    def search(self, searchkey : str):
        if searchkey in self.data:
            return self.data[searchkey]
        else:
            return None