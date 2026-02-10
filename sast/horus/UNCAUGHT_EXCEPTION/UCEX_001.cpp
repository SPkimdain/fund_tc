#include <stdexcept>

extern void* _alloca(unsigned size);

/* UCEX_001 - simple case1 */

void UCEX_001_function1() {
  int size = 1000;
  int errcode = 0;
  void * pData = 0;

  pData = _alloca(size); //@violation UNCAUGHT_EXCEPTION

}

void UCEX_001_function2() {
  int size = 1000;
  int errcode = 0;
  void * pData = 0;

  try {
    pData = _alloca(size); //It's ok.
  }
  catch(std::exception& ex) {
    //...
    return;
  }
}
