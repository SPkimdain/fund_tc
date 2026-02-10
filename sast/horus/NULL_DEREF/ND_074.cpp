
/* ND_074 - smart pointer compare operator */

class ND_074_Class_ptr {
public:
  ND_074_Class_ptr(int* v) : value(v) {}

  bool operator==(int null) {
    if(null != 0) {
      return false;
    }
    return value == 0;
  }

  bool operator!=(int null) {
    return !operator==(null);
  }

  int operator*() const { return *value; }

  int* getValue() const { return value; }

private:
  int* value;
};

int ND_074_function() {

  ND_074_Class_ptr obj = 0;
  ND_074_Class_ptr obj2 = 0;

  int* xval = obj.getValue();

  if(obj != 0 && *obj == 20) { //It's ok. short circuit.
    
    int* y = xval;
    
    return 0;
  }

  if(*obj2 == 30) { //@violation NULL_DEREF
    return 1;
  }

  return -1;
}
