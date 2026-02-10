//@checker DO_NOT_DISCARD_FUNCTION_RETURN_VALUE


class A
{
  int b;
public:
  A(int a) : b(a) {}
  A operator+(const A& rhs)
  {
    return A(this->b + rhs.b);



  }


};


int test(int a)
{
  return a+5;
}

int main()
{
  (void)test(4);
  test(5); //@violation DO_NOT_DISCARD_FUNCTION_RETURN_VALUE
  (void)test(6);
  long b = (long)test(7);
  int c = test(7);
  A a = A(8);
  a+9;
}
