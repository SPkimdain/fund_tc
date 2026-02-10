#include <stdlib.h>

/* MMTD_016 - template initializer list */
template<typename T>
class MMTD_016_Class {
public:
  MMTD_016_Class(T* arg) : value(arg) {}

  ~MMTD_016_Class() {
    if(value != 0) {
      delete value;
    }
  }

private:
  T* value;
};

void MMTD_016_function(int flag) {
  if(flag > 0){
    double* data = static_cast<double*>(malloc(10 * sizeof(double)));
    MMTD_016_Class<double> obj(data);
  } //@violation MISMATCH.MALLOC_TO_DELETE  
}
