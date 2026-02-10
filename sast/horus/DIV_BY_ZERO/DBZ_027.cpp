

/* DBZ_027 - virtual function call */
class DBZ_027_Base {
public:
  virtual int doSomethingVirtual(int x) {
    return 1000 / (x + 5);
  }
};

class DBZ_027_Derived : public DBZ_027_Base
{
public:
  virtual int doSomethingVirtual(int x) {
    return 1000 / (x + 10); // DIV_BY_ZERO
  }
};

void DBZ_027_function() {
  DBZ_027_Base* inst1 = new DBZ_027_Base;
  DBZ_027_Base* inst2 = new DBZ_027_Derived;

  inst1->doSomethingVirtual(-10);
  inst2->doSomethingVirtual(-10); //@violation DIV_BY_ZERO

  delete inst1;
  delete inst2;
}
