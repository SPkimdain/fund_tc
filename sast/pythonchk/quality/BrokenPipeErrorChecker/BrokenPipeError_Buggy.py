import subprocess as sub

p = sub.Popen(["ls", "-al", "../"], stdin=sub.PIPE, stdout=sub.PIPE)

p.stdout.read()

# BUG, BrokenPipeError
p.stdin.write("ls\n")              # @violation