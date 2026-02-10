//@checker MAKE_BINARY_OPERATORS_NONMEMBERS
class complex
{
 public:
  complex( float r, float i = 0 );
  complex operator+( const complex& rhs );

  float r;
  float i;
};

complex operator+(const complex& a, const complex& b) {
  complex tmp(a.r + b.r, a.i + b.i);
  return tmp;
};


complex complex::operator+( const complex& rhs ) { //@violation MAKE_BINARY_OPERATORS_NONMEMBERS
  complex tmp(this->r + rhs.r, this->i + rhs.i);
  return tmp;
}

void Add() {
  complex a( 1, 0 );
  a = a + 2;
  a = 2 + a;
  // fine: 2 is converted to complex
  // error: no applicable operator +
}
