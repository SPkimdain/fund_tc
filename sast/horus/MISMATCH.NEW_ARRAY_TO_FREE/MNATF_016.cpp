#include <stdlib.h>

/* MNATF_016 - template initializer list */
template<typename T>
class MNATF_016_Class {
public:
  MNATF_016_Class(T* arg) : value(arg) {}

  ~MNATF_016_Class() {
    if(value != 0) {
      free(value);
    }
  }

private:
  T* value;
};

void MNATF_016_function(int flag) {
  if(flag > 0){
    double* data = new double[10];
    MNATF_016_Class<double> obj(data);
  } //@violation MISMATCH.NEW_ARRAY_TO_FREE  
}
