import os

oldmask = os.umask(0o022)        # @violation
f = os.open("test", os.O_CREAT, 0o777)
os.umask(oldmask)

oldmask2 = os.umask(0o22)         # good
f2 = os.open("test2", os.O_CREAT, 0o777)
os.umask(oldmask2)