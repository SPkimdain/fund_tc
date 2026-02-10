
/* NDMC_002 - assume parameter */

void NDMC_002_function(int* ptr) {
  int* localPtr = ptr;
  int index = 0;
  
  while(localPtr) {
    index++;
    if(index > 10) {
      break;
    }
  }

  *localPtr = 10; //@violation NULL_DEREF.MISSING_CHECK
}

