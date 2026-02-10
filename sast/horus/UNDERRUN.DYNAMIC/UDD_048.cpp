
/* UDD_048 - member call */
class UDD_048_Class {
public:
  int valueReturn() { return -1; }
};

void UDD_048_function() {
  UDD_048_Class obj;
  UDD_048_Class* objPtr = &obj;
  int* p = new int[10];
  if(p == 0) {
    return;
  }

  p[objPtr->valueReturn()] = 10; //@violation UNDERRUN.DYNAMIC

  delete[] p;
}
