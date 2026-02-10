//@checker DO_NOT_USE_CONST_FOR_SYMBOLIC_CONSTANT

int a = 0;
const int b = 1;  //@violation DO_NOT_USE_CONST_FOR_SYMBOLIC_CONSTANT
float c = 2.0;
const float d = 3.0;  //@violation DO_NOT_USE_CONST_FOR_SYMBOLIC_CONSTANT

void foo() {
  int e = 0;
  const int f = 1;   //@violation DO_NOT_USE_CONST_FOR_SYMBOLIC_CONSTANT
  float g = 2.0;
  const float h = 3.0;  //@violation DO_NOT_USE_CONST_FOR_SYMBOLIC_CONSTANT
}
