import os


def test(cmd):
    home = os.getenv('APPHOME')
    cmd = home + cmd
    os.system(cmd)          # @violation
