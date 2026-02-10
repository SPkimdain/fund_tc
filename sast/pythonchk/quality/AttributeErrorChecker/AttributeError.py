import string

a = string.capitalize("jamie")  # @violation
a = string.capwords("jamie")

b = "hello".lowercase()  # @violation
b = "hello".lower()

