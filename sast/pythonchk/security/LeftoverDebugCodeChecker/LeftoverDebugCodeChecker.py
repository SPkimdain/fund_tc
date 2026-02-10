import pdb  # @violation
import logging
from pdb import set_trace  # @violation


def leftover_code_1():
    file = None
    try:
        filename = "test1.txt"
        logging.debug("FILE NAME : " + filename)  # @violation
        file = open(filename)
    except FileNotFoundError:
        print('File Except 1')
    finally:
        if file is not None:
            file.close()


def leftover_code_2():
    file = None
    try:
        filename = "test2.txt"
        pdb.set_trace()  # @violation
        file = open(filename)
    except FileNotFoundError:
        print('File Except 2')
    finally:
        if file is not None:
            file.close()


def leftover_code_3():
    file = None
    try:
        filename = "test3.txt"
        # delete debug code                         # good
        file = open(filename)
    except FileNotFoundError:
        print('File Except 3')
    finally:
        if file is not None:
            file.close()


leftover_code_1()
leftover_code_2()
leftover_code_3()

from flask import Flask

app = Flask(__name__)
app.debug = True # @violation


@app.route('/')
def hello_world():
    return 'Hello World!'


if __name__ == '__main__':
    app.run()

app = Flask(__name__)
app.debug = False


@app.route('/')
def hello_world():
    return 'Hello World!'


if __name__ == '__main__':
    app.run()
