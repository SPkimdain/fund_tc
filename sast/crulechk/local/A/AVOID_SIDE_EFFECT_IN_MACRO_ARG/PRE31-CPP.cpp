// @checker AVOID_SIDE_EFFECT_IN_MACRO_ARG
#define ABS(x) (((x) < 0) ? -(x) : (x))

inline int abs(int x)
{
  return (((x) < 0) ? -(x) : (x));
}

void noncompliant(int n)
{
  int m;
  m = ABS(++n);   // @violation AVOID_SIDE_EFFECT_IN_MACRO_ARG
}


void compliant(int n)
{
  int m;
  ++n;
  m = ABS(n);     // safe
}

void compliant_code_using_inline(int n)
{
  int m;
  m = abs(n);     // safe
}
