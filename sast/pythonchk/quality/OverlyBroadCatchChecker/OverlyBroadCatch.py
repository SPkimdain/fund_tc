import sys


def overly_broad_catch_1():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except Exception:  # @violation
        print("Exception 1")
    finally:
        if f is not None:
            f.close()


def overly_broad_catch_2():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except Exception as e:  # @violation
        print("Exception 2")
    finally:
        if f is not None:
            f.close()


def overly_broad_catch_3():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except:  # @violation
        print("Exception 3")
    finally:
        if f is not None:
            f.close()


def overly_broad_catch_4():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except (KeyError, FileNotFoundError):  # good
        print("Exception 4")
    finally:
        if f is not None:
            f.close()


def overly_broad_catch_5():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except FileNotFoundError:  # good
        print("FileNotFoundError")
    except:  # good      #if on/off option is 'off' -> violation
        print("Exception 5")
    finally:
        if f is not None:
            f.close()


def overly_broad_catch_6():
    filename = "nothing.txt"
    f = None
    try:
        f = open(filename)
    except FileNotFoundError:  # good
        print("FileNotFoundError")
    finally:
        if f is not None:
            f.close()


def get_content():
    try:
        f = open('myfile.txt')
        s = f.readline()
        i = int(s.strip())
    # 예외 처리를 세분화 할 수 있음에도 광범위하게 사용하여 예기치 않은
    # 문제가 발생할 수 있다.
    except:     # @violation
        print("Unexpected error ")


def get_content():
    try:
        f = open('myfile.txt')
        s = f.readline()
        i = int(s.strip())
    # 발생할 수 있는 오류의 종류와 순서에 맞춰서 예외 처리 한다.
    except FileNotFoundError:
        print("file is not found")
    except OSError:
        print("cannot open file")
    except ValueError:
        print("Could not convert data to an integer.")