// @checker BAD_OPERATOR.TOO_MANY_LOGICAL_OPERATIONS


void foo()
{
  int a; int b; int c;
  a = a + b * c; // @violation BAD_OPERATOR.TOO_MANY_LOGICAL_OPERATIONS
  b = a + (b * c);
  c = b * c + a;
}
