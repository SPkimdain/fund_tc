import fractions

class Div():
  def division(a):
    return 5/a

def division(a):
  return 2/a

c=3
b=6/Div.division(c)
d=a/division(0)            # @violation
a=3/(3)
a=6/((Div.division(c)))
a=True / False             # @violation

def method():
  return 0

fractions.Fraction(a,0)  # @violation
fractions.Fraction(2,method())  # @violation