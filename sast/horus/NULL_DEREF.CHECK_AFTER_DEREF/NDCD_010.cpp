//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_010 - member call */
class NDCD_010_Class {
public:
  NDCD_010_Class(int* v) : value(v) {}

  int* getPtrValue() { return value; }

private:
  int* value;
};

int NDCD_010_function(NDCD_010_Class& obj, int flag) {
  NDCD_010_Class* objPtr = &obj;

  int* p = objPtr->getPtrValue();

  *p = 100;

  if(flag > 10 && p) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    return 0;
  }

  return 1;
}
