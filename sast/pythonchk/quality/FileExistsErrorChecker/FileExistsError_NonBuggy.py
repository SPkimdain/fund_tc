import os

def non_buggy_mkdir(path):
    try:
        os.mkdir(path)
    except FileExistsError:
        print ('Directory not created.')

path = "C:"
non_buggy_mkdir(path)