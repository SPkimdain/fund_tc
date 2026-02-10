#include <stdlib.h>

/* MNATD_016 - template initializer list */
template<typename T>
class MNATD_016_Class {
public:
  MNATD_016_Class(T* arg) : value(arg) {}

  ~MNATD_016_Class() {
    if(value != 0) {
      delete value;
    }
  }

private:
  T* value;
};

void MNATD_016_function(int flag) {
  if(flag > 0){
    double* data = new double[10];
    MNATD_016_Class<double> obj(data);
  } //@violation MISMATCH.NEW_ARRAY_TO_DELETE  
}
