//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_015 - offset check. */

int NDCD_015_function1(int** twoDepthPtr) {
  int ret = 0;
  int* tdp = *twoDepthPtr;
  *tdp = 10;

  tdp += 1;

  tdp = tdp + 1;

  if(tdp != 0) { //it's ok. But this code is weird.
    *tdp = 20;
  }

  return ret;
}

int NDCD_015_function2(int* p) {
  int ret = 0;
  int* pptr = p;
  *pptr = 10;

  pptr += 1;

  pptr = pptr + 1;

  if(pptr != 0) { //it's ok. But this code is weird.
    *pptr = 20;
  }

  return ret;
}


void NDCD_015_function3(int* p) {
  *p = 100;

  if(p) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    int i = 0;
  }
}
