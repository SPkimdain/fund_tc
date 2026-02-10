//@checker ENSURE_USING_NAMESPACE_POSITION

using namespace std; // @violation ENSURE_USING_NAMESPACE_POSITION

#include "custom_typedef.h"

void ENSUNPOS_001_function() {
  int ret = 0;
  
  ret++;
  ret++;
  
}
