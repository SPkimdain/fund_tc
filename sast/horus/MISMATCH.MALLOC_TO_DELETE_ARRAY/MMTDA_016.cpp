#include <stdlib.h>

/* MMTDA_016 - template initializer list */
template<typename T>
class MMTDA_016_Class {
public:
  MMTDA_016_Class(T* arg) : value(arg) {}

  ~MMTDA_016_Class() {
    if(value != 0) {
      delete[] value;
    }
  }

private:
  T* value;
};

void MMTDA_016_function(int flag) {
  if(flag > 0){
    double* data = static_cast<double*>(malloc(10 * sizeof(double)));
    MMTDA_016_Class<double> obj(data);
  } //@violation MISMATCH.MALLOC_TO_DELETE_ARRAY  
}
