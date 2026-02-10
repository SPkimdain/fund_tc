//@checker DECLARE_TYPE_IN_HEADER_FILES
#include "Noncompliant.h"

#include "CompliantExternal.h"
#include "CompliantInternal.h"

int IMABSTDT_001_function() {
  int ret = 0;
  
  return ret++;
}

  
