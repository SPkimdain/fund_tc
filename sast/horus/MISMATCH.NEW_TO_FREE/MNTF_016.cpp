#include <stdlib.h>

/* MNTF_016 - template initializer list */
template<typename T>
class MNTF_016_Class {
public:
  MNTF_016_Class(T* arg) : value(arg) {}

  ~MNTF_016_Class() {
    if(value != 0) {
      free(value);
    }
  }

private:
  T* value;
};

void MNTF_016_function(int flag) {
  if(flag > 0){
    double* data = new double(5.5F);
    MNTF_016_Class<double> obj(data);
  } //@violation MISMATCH.NEW_TO_FREE  
}
