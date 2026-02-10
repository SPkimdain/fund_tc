//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_013 - function call */

class NDCD_013_Class {
public:
  const NDCD_013_Class* getObj() const {
    return this;
  }
  
  void setValue(int v) {
    value = v;
  }
private:
  int value;
};

NDCD_013_Class* NDCD_013_functino1(NDCD_013_Class* p) {
  p->setValue(10);
  return p;
}

int NDCD_013_function2(NDCD_013_Class* val) {
  int ret = 0;
  const NDCD_013_Class* ptr = NDCD_013_functino1(val)->getObj();
  if(ptr) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    ret++;
  }

  return ret;
}

