class VerbManager:
    # Takes a dictionary of instances of verb
    def __init__(self, verbs, noverb = "The verb you inputted does not exist."):
        if type(verbs) is not dict:
            raise ValueError("ERROR: verbs parameter should be a dictionary instead is a " + type(verbs))

        self.verbs = verbs
        self.noverb = noverb

    def exec(self, userinput, dao):
        tokens = userinput.split(" ")
        verb = tokens[0]

        if verb in self.verbs:
            return self.verbs[verb].do(tokens[1:], dao)
        else:
            return self.noverb
