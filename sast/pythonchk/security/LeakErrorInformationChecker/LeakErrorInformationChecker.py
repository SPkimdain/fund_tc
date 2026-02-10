import logging
import traceback

def leak_error_information_1():
    file = None
    try:
        filename = "test1_1.txt"
        file = open(filename)
    except FileNotFoundError:
        try:
            filename = "test1_1.txt"
            file = open(filename)
        except FileNotFoundError as e:
            print('Except 1: ' + str(e))            # @violation
            print('Hello' + str(e) + 'World')       # @violation
        finally:
            if file is not None:
                file.close()

def leak_error_information_2():
    file = None
    try:
        filename = "test2.txt"
        file = open(filename)
    except FileNotFoundError as e:
        e1 = 'Except 2: '
        print(e1)
        print(e)                                    # @violation
        print(str(e))                               # @violation
    finally:
        if file is not None:
            file.close()

def leak_error_information_3():
    file = None
    try:
        filename = "test4.txt"
        file = open(filename)
    except FileNotFoundError:
        print('Except 4: ')
        logging.error("File Not Found")             # good
    finally:
        if file is not None:
            file.close()

def leak_error_py2():
    file = None
    try:
        filename = "test1_1.txt"
        file = open(filename)
    except FileNotFoundError:
        try:
            filename = "test1_1.txt"
            file = open(filename)
        except FileNotFoundError, e:
            print 'Except 1:', e                    # @violation
            print 'Hello' + str(e) + 'World'        # @violation
        finally:
            if file is not None:
                file.close()
