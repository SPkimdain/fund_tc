//@checker OVERLOADED_FUNCTION_TEMPLATE_NOT_BE_SPECIALIZED

template <typename T> void f (T);
template <> void f<int*> (int*);

void b ( int * i)
{
  f ( i );
}
