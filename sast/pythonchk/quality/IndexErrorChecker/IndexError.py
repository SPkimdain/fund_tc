import sys

a = "abcde"
n = input()
print(a[n])  # @violation
print(a[-7]) # @violation

print(sys.argv[0])
print(sys.argv[1]) # @violation

a_list = ['a', 'b', 'mpilgrim', 'z', 'example']
print(a_list[-6])  # @violation
print(a_list[-3])

a_list.append(['c','d','e'])
print(a_list[5][3])  # @violation

a_list.pop(-1)  # @violation


