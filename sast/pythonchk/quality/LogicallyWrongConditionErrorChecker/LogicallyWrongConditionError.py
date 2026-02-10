import random

#logically Wrong Condition
def redundant_condition(int):
  if int > 0:
    print("reachable")
  elif int <= 0:
    print("reachable")
  elif int == 4:                                # @violation
    print("unreachable")

def unreachable_condition(int):
  while int > 0:
    if int == -1:								# @violation
      print("wrong")
    int = int + 1
  for i in range(0,5):
    if i == -1:									# @violation
      print("wrong")

def logical_error(int):
  x = int + 1
  if x == int:									# @violation
    print("wrong")


a = random.randint(-5, 5)
redundant_condition(a)
unreachable_condition(a)
logical_error(a)