
/* OV_048 - member call */
class OV_048_Class {
public:
  int valueReturn() { return 10; }
};

void OV_048_function() {
  OV_048_Class obj;
  OV_048_Class* objPtr = &obj;
  int p[10] = { 0, };
  p[objPtr->valueReturn()] = 10; //@violation OVERRUN.STATIC
}
