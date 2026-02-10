import os
import tempfile

tmp1 = open(os.tmpnam(), mode='rw')     # @violation
tmp1.close()
tmp2 = open(os.tempnam(), mode='rw')    # @violation
tmp2.close()
tmp3 = tempfile.TemporaryFile()         # good
tmp3.close()
tmp4 = open("mygeneralfile", mode='rw') # good
tmp4.close()
tmp5 = open("mytempfile", mode='rwx')   # @violation
tmp5.close()
tmp6 = open("badtmp", mode='rwx')       # @violation
tmp6.close()