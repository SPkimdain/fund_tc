
/* DF_011 - ctor chain */
class DF_011_Class1 {
public:
  DF_011_Class1() : value(0) {
    value = new int(10);
  }
  
  void release() {
    delete value;
  }
  
  ~DF_011_Class1() {
    delete value;
  }
  
private:
  int* value;
};

class DF_011_Class2 {
public:
  DF_011_Class2() : value2(new DF_011_Class1()) {    
  }
  
  void elementRelease() {
    value2->release();
  }

  ~DF_011_Class2() {
    delete value2;
  }

private:
  DF_011_Class1* value2;
};

void DF_011_function(bool flag) {
  if(flag > 0) {
    DF_011_Class2 obj;
    obj.elementRelease();
  } //@violation DOUBLE_FREE
}


