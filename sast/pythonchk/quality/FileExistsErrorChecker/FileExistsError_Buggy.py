import os

def buggy_mkdir(path):
    # BUG, FileExistsError
    os.mkdir(path)                # @violation

path = "C:"
buggy_mkdir(path)
