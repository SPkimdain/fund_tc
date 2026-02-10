
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

private:
  mutable T* value;
};

void ND_060_function(int flag) {
  if(flag > 0){
    ND_060_Class<int> obj(new int());
    obj.setData(100); //It's ok.
  }
  else {
    ND_060_Class<double> obj2(0);
    obj2.setData(10.5F); //@violation NULL_DEREF
  }
}

