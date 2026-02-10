//@checker OVERLOADED_FUNCTION_TEMPLATE_NOT_BE_SPECIALIZED
//@checker DO_NOT_OVERLOAD_FUNCTION_WITH_SPECIALIZATION

void f (short a)
{
  int b= a *2 ;
}
template <typename T> void f (T a)
{
  int b= a * 4;
}

void b (short s)
{
  f<>(s);
  f(s); //@violation DO_NOT_OVERLOAD_FUNCTION_WITH_SPECIALIZATION
  f(s+1); //@violation DO_NOT_OVERLOAD_FUNCTION_WITH_SPECIALIZATION

  f<>(s+1);
}
