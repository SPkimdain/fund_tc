//@checker IMPROPER_OVERLOAD_OF_SUBSCRIPT_OPERATOR
// #include <iostream>

class Array
{
 public:
  Array()
  {
    for ( int i = 0; i < Max_Size; ++i )
    {
      x[ i ] = i; }
  }
  int& operator[] ( const int a ) //@violation IMPROPER_OVERLOAD_OF_SUBSCRIPT_OPERATOR
  {
    // std::cout<< "nonconst" << std::endl;
    return x[ a ];
  }
  int operator[] ( const int a ) const //@violation IMPROPER_OVERLOAD_OF_SUBSCRIPT_OPERATOR
  {
    // std::cout << "const" << std::endl;
    return x[ a ];
  }
  int operator[] ( const double a )
  {
    // std::cout << "const" << std::endl;
    return x[ 0 ];
  }
  int operator[] ( const double a ) const
  {
    // std::cout << "const" << std::endl;
    return x[ 0 ];
  }


 private:
  enum { Max_Size = 10 };
  int x[ Max_Size ];
};
int main()
{
  Array a;
  int i=a[3]; a[ 3 ] = 33;
  const Array ca;
  i = ca[ 3 ];
  // ca[ 3 ] = 33;
  return 0;
}
