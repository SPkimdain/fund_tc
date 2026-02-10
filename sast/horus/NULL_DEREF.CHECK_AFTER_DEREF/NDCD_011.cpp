//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* ND_060 - template initializer list */
template<typename T>
class ND_060_Class {
public:
  ND_060_Class(T* arg) : value(arg) {}

  ~ND_060_Class() {
    if(value != 0) {
      delete value;
    }
  }

  void setData(T data) {
    *value = data;
  }

  T* getData() { return value; }

private:
  mutable T* value;
};

bool ND_060_function(int flag, double* x) {
  *x = 200.5F;

  if(flag > 0){
    ND_060_Class<int> obj(new int());
    obj.setData(100); //It's ok.
  }
  else {
    ND_060_Class<double> obj2(x);
    if(obj2.getData()) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
      return false;
    }
  }

  return true;
}

