//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_014 - ignore null-checked pointer referenced. */

int NDCD_014_function1(int* p) {
  int ret = 0;
  int* pptr = p;
  if(pptr != 0) {
    ret += *pptr; 
  }

  if(pptr != 0) { //It's ok.
    ret += 10;
    ret += *pptr;
  }
  

  return ret;
}


int NDCD_014_function2(int* p) {
  int ret = 0;
  int* pptr = p;

  ret += *pptr;

  if(pptr) {  //@violation NULL_DEREF.CHECK_AFTER_DEREF
    ret += 10;
  }

  return ret;
}
