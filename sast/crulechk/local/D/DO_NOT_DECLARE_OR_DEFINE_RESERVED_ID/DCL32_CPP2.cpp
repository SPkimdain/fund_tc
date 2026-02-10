// @checker DO_NOT_DECLARE_OR_DEFINE_RESERVED_ID

#include <cstddef>

unsigned int operator"" x(const char*, std::size_t) {  //It's ok.
  int dummy = 1;
  return dummy;
} 

unsigned int operator"" _x(const char*, std::size_t) { // @violation DO_NOT_DECLARE_OR_DEFINE_RESERVED_ID
  int dummy = 1;
  return dummy;
}

