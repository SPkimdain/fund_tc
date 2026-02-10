import copy


class BadTest:
    def __init__(self):
        self.__colors = ['red', 'orange', 'black', 'white', 'blue']

    def get_colors(self):
        return self.__colors  # @violation


class BadTest:
    __colors = ['red', 'orange', 'black', 'white', 'blue']

    def get_colors(self):
        return self.__colors  # @violation


bad_test = BadTest()
color = bad_test.get_colors()  # ['red', 'orange', 'black', 'white', 'blue']
color[0] = 'none'
print(bad_test.get_color())  # ['none', 'orange', 'black', 'white', 'blue']


class GoodTest:
    __colors = ['red', 'orange', 'black', 'white', 'blue']

    def get_colors1(self):
        return self.__colors[:]  # good

    def get_colors2(self):
        return copy.deepcopy(self.__colors)  # good


good_test = GoodTest()
color = good_test.get_colors1()  # ['red', 'orange', 'black', 'white', 'blue']
color[0] = 'none'
print(good_test.get_color())  # ['none', 'orange', 'black', 'white', 'blue']


class BadUserObj:
    __private_variable = []

    def __init__(self):
        pass

    # private 배열을 리턴하는 public 메소드를 사용하는 경우 취약함
    def get_private_member(self):
        return self.__private_variable  # @violation


class GoodUserObj:
    __private_variable = []

    def __init__(self):
        pass

    # private 배열을 반환하는 경우 [:]를 사용하여 외부와 내부의
    # 배열이 서로 참조되지 않도록 해야 한다
    def get_private_member(self):
        return self.__private_variable[:]  # good
