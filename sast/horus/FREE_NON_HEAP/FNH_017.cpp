
/* FNH_017 - object copy */
class FNH_017_Class {
public:
  FNH_017_Class(int* v) : value(v) {}
  ~FNH_017_Class() {
    release();
  }

  void reset() {
    value = 0;
  }

  void release() {
    if(value != 0) {
      delete value;
      value = 0;
    }
  }

private:
  int* value;
};

void FNH_017_function() {
  int value = 10;
  int* value2 = new int(50);
  FNH_017_Class obj(&value);

  FNH_017_Class obj2(value2);  
  obj2.release(); //It's ok.

  obj2 = obj;
  
  obj.reset();

  obj2.release(); //@violation FREE_NON_HEAP
}


