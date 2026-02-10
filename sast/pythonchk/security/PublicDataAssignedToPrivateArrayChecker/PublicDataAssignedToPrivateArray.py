import copy


class BadTest2:

    def __init__(self):
        self.__colors = None
        __colors = []

    def get_colors(self):
        return self.__colors[:]

    def set_colors(self, colors: [str]):
        self.__colors = colors  # @violation


class BadTest:
    __colors = None

    def get_colors(self):
        return self.__colors[:]

    def set_colors(self, colors):
        self.__colors = colors  # @violation


color = ['red', 'orange', 'black', 'white', 'blue']

bad_test = BadTest()
bad_test.set_colors(color)
color[0] = 'none'
print(bad_test.get_colors())  # ['none', 'orange', 'black', 'white', 'blue']


class GoodTest:
    __colors = None

    def get_colors(self):
        return self.__colors[:]

    def set_colors1(self, colors):
        self.__colors = colors[:]  # good

    def set_colors2(self, colors):
        self.__colors = copy.deepcopy(colors)  # good


color = ['red', 'orange', 'black', 'white', 'blue']

good_test = GoodTest()
good_test.set_colors1(color)  # ['red', 'orange', 'black', 'white', 'blue']
color[0] = 'none'
print(good_test.get_colors())  # ['red', 'orange', 'black', 'white', 'blue']


class BadUserObj:
    __private_variable = []

    def __init__(self):
        pass

    # private 배열에 외부 값을 바로 대입하는 public 메소드를 사용하는 경우 취약함
    def set_private_member(self, num):
        self.__private_variable = num  # @violation


class GoodUserObj:
    def __init__(self):
        self.__privateVariable = []

    # private 배열에 외부 값을 바로 대입하는 경우 [:]를 사용하여
    # 외부와 내부의 배열이 서로 참조되지 않도록 해야 함
    def set_private_member(self, num):
        self.__privateVariable = num[:]  # good
