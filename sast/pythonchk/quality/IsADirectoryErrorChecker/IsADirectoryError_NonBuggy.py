import os

path = "C:"
# assume that file.txt exists
f = open("file.txt")
f.write(stuff)
try:
    os.replace(f.name, path)
except IsADirectoryError:
    print ("Is a directory")
finally:
    f.close()