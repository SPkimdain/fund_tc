#Number of Arguments error
class test(object):
    def __init__(self, int, string):
        self.int = int
        self.name = string

def arguments(int, string, bug):
    a = int
    b = string
    c = bug
    print("hi")

def correct(int, string, bug = 3):
    print("hi")

arguments(1, "hi")  # @violation
correct(1, "hi")
a= test(1)           # @violation