
class Runner:
    # Dao, OutputManager and VerbManager
    def __init__(self, dao, outman, veman):
        self.dao = dao
        self.outman = outman
        self.veman = veman

    def run(self):
        input = ''
        # Make sure to implement a quit verb before calling run
        while self.dao.is_awake():
            self.dao.check_beats(self.outman)
            input = self.outman.ask_user_input("")
            self.veman.exec(input, self.dao)