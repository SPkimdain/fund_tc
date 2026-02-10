//@checker BAD_INCLUDE.DUPLICATED
#include "file_target_excluded.h"
#include "file_target_excluded.h" //@violation BAD_INCLUDE.DUPLICATED

void BINCDUP_001_function() {
  int x = 0;
  return;
}
  

