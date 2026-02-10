#include <stdlib.h>

/* MNTDA_016 - template initializer list */
template<typename T>
class MNTDA_016_Class {
public:
  MNTDA_016_Class(T* arg) : value(arg) {}

  ~MNTDA_016_Class() {
    if(value != 0) {
      delete[] value;
    }
  }

private:
  T* value;
};

void MNTDA_016_function(int flag) {
  if(flag > 0){
    double* data = new double(5.5F);
    MNTDA_016_Class<double> obj(data);
  } //@violation MISMATCH.NEW_TO_DELETE_ARRAY  
}
