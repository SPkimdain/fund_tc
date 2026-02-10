
/* ND_048 - member call */
class ND_048_Class {
public:
  int* nullReturn() { return 0; }
};

void ND_048_function() {
  ND_048_Class obj;
  ND_048_Class* objPtr = &obj;
  int* p = objPtr->nullReturn();
  *p = 100; //@violation NULL_DEREF
}
