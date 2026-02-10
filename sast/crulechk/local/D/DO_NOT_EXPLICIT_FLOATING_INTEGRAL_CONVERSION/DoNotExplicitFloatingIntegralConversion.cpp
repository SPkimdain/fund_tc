//@checker DO_NOT_EXPLICIT_FLOATING_INTEGRAL_CONVERSION

void DNEFIC_F1()
{
  int a=10,b=20,c=30;
  float f=0;
  f =  static_cast< float > ( (a / b) + c ); //@violation DO_NOT_EXPLICIT_FLOATING_INTEGRAL_CONVERSION
  f =  static_cast< float > ( a / b ); //@violation DO_NOT_EXPLICIT_FLOATING_INTEGRAL_CONVERSION
  c = a / b;
  f =  static_cast< float > ( c );
  f =  static_cast< float > ( a ) / b ;


}


void DNEFIC_F2()
{
  float a=10,b=20,c=30;
  int i=0;

  i =  static_cast< int > ( a / b ); //@violation DO_NOT_EXPLICIT_FLOATING_INTEGRAL_CONVERSION
  c = a / b;
  i =  static_cast< int > ( c );
  i =  static_cast< int > ( a ) / b ;


}
