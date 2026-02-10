//@checker OVERLOADED_FUNCTION_TEMPLATE_NOT_BE_SPECIALIZED

template <typename T>
void f (T a)
{
  a++;
  return ;
}
template <typename T>
void f (T* a)
{
  a--;
  return ;
}

template <>
void f<int*> (int* a) //@violation OVERLOADED_FUNCTION_TEMPLATE_NOT_BE_SPECIALIZED
{
  int b = *a;
  *a = *a + b;
  return ;
}


void b ( int * i)
{
  f ( i );  //violation
}
