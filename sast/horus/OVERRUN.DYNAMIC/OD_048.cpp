
/* OD_048 - member call */
class OD_048_Class {
public:
  int valueReturn() { return 10; }
};

void OD_048_function() {
  OD_048_Class obj;
  OD_048_Class* objPtr = &obj;
  int* p = new int[10];
  if(p == 0) {
    return;
  }

  p[objPtr->valueReturn()] = 10; //@violation OVERRUN.DYNAMIC

  delete[] p;
}
