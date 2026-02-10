//@checker DO_NOT_USE_NULL_MACRO
#include <stddef.h>

void function(int* pValue) {
  if(pValue == NULL) { //@violation DO_NOT_USE_NULL_MACRO
 
  }
}