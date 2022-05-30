
class Runner:
    def __init__(self, dao):
        self.dao = dao

    def run(self):
        if self.dao.is_awake():
            print("I am awake and running now")