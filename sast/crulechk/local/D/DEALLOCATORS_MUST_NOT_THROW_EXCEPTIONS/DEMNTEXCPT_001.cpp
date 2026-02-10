//@checker DEALLOCATORS_MUST_NOT_THROW_EXCEPTIONS
#include <stdio.h>
#include <stdexcept>

using namespace std;


class DEMNTEXCPT_001_Class {
public:
  DEMNTEXCPT_001_Class() {}
  static void* operator new[](size_t);
  static void operator delete[](void *ptr) {
    if(ptr == 0) {
      throw runtime_error("deallocating a bad pointer"); //@violation DEALLOCATORS_MUST_NOT_THROW_EXCEPTIONS   
    }
  }
};

void DEMNTEXCPT_001_function(unsigned int nelems) {
  DEMNTEXCPT_001_Class *array = new DEMNTEXCPT_001_Class[nelems];

  delete[] array;
}

