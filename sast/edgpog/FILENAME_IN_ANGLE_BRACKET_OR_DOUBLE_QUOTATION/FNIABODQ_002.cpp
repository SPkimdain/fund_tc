//@checker FILENAME_IN_ANGLE_BRACKET_OR_DOUBLE_QUOTATION

#include <stdio.h> //It's ok.

#include FNIABODQ_002.hpp //@violation FILENAME_IN_ANGLE_BRACKET_OR_DOUBLE_QUOTATION

int FNIABODQ_002_function(int x) {
  x++;
  
  return x;
}
