import sys

class OutputManager:
    def __init__(self, caret = '=>'):
        self.caret = caret

    def ask_user_input(self, ask = ""):
        return input(ask + '\n' + self.caret)
    
    def ask_user_numeric_input(self, ask, min=-sys.maxsize + 1, max = sys.maxsize):
        number = sys.maxsize

        while(number < min or number > max):
            try:
                number = int(self.ask_user_input(ask))
            except ValueError:
                print("Incorrect input value")
        
        return number

    # TODO make case-agnostic
    def ask_choice(self, ask:str, choices:list, wronginput:str="Wrong Input"):
        output = ""
        input = ""
        done = False

        while not done:
            input = self.ask_user_input(ask)
            if input in choices:
                output = input
                done = True
            else:
                print(wronginput)

        return output