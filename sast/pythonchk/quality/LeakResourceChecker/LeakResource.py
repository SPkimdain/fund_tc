import io
import tempfile


def leak_resource_1():
    f = open("test.txt", encoding='UTF8')  # @violation
    data = f.read()
    print(data)


def leak_resource_6(n):
    f = open("test.txt", encoding='UTF8')  # @violation
    if n > 0:
        data = f.read()
        print(data)
        f.close()
    elif n > -2:
        print("elif")
    else:
        print("else")


def leak_resource_7():
    try:
        f = open("test.txt", encoding='UTF8')  # @violation
        data = f.read()
        print(data)
        f.close()
    except FileNotFoundError:
        print("ERROR")
    finally:
        print("FINALLY")


def leak_resource_8():
    try:
        try:
            f = open("test.txt", encoding='UTF8')  # @violation
            data = f.read()
            print(data)
            f.close()
        except:
            print("")

    except FileExistsError:
        print("ERROR")
    finally:
        print("FINALLY")


def leak_resource_9():
    f = open("test.txt", encoding='UTF8')  # good
    data = f.read()
    print(data)
    f.close()


def leak_resource_10():
    f = open("test.txt", encoding='UTF8')  # good
    data = f.read()
    print(data)
    f = None


def leak_resource_11():
    with open("test.txt", encoding='UTF8') as f:  # good
        data = f.read()
        print(data)


def leak_resource_12():
    with open("test.txt", encoding='UTF8') as f:  # good
        with open("test1.txt", encoding='UTF8') as f1:
            data = f.read()
            print(data)


def leak_resource_13():
    with open("test.txt", encoding='UTF8') as f:
        f1 = open("test.txt", encoding='UTF8')  # @violation
        data = f1.read()
        print(data)


def leak_resource_14():
    try:
        f = open("test.txt", encoding='UTF8')  # good
        data = f.read()
        print(data)
    except FileNotFoundError:
        print("ERROR")
    finally:
        f.close()


def leak_resource_15():
    lines = None
    try:
        f = open('config.cfg')  # @violation
        lines = f.readlines()
        # try 절에서 할당한 자원이 반환(close)되기 전에
        # 예외가 발생하면 할당된 자원이 시스템에 반환되지 않음
        f.close()
        return lines
    except Exception as e:
        print(e)
    return ''


def leak_resource_16():
    # with 절을 빠져나갈 때 f를 시스템에 반환
    with open('filename.py') as f:
        print(f.read())

        lines = None
        try:
            ff = open('config.cfg')  # good
            lines = ff.readlines()
        except Exception as e:
            print(e)
        finally:
            ff.close()
        return lines


def leak_resource_17():
    # with 절을 빠져나갈 때 f를 시스템에 반환
    try:
        with open('filename.py') as f:
            print(f.read())
        lines = None
        ff = open('config.cfg')  # good
        lines = ff.readlines()
    except Exception as e:
        print(e)
    finally:
        ff.close()
    return lines


def leak_resource_18():
    with open("test1.txt", encoding='UTF8') as f1:  # good
        with open("test2.txt", encoding='UTF8') as f2:
            data2 = f2.read()
            print(data2)

        data1 = f1.read()
        print(data1)
