
/* DBZ_048 - member call */
class DBZ_048_Class {
public:
  int zeroReturn() { return 0; }
};

void DBZ_048_function() {
  DBZ_048_Class obj;
  DBZ_048_Class* objPtr = &obj;
  int p = objPtr->zeroReturn();
  int ret = 100 / p; //@violation DIV_BY_ZERO
}
