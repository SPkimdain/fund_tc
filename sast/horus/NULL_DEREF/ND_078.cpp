
/* ND_078 - dynamic_cast failed handle */
class ND_078_Base {
public:
  ND_078_Base() : value(0) {}

  virtual ~ND_078_Base() {}
private:
  int value;
};

class ND_078_Child : public ND_078_Base {
public:
  ND_078_Child() : ND_078_Base(), value2(0) {}

  int getValue2() { return value2; }

  virtual ~ND_078_Child() {}
private:
  int value2;
};

void ND_078_function(ND_078_Base* obj, int flag) {
  ND_078_Base* base1 = new ND_078_Base();
  ND_078_Child* child2 = new ND_078_Child();

  ND_078_Child* cast1 = dynamic_cast<ND_078_Child*>(obj); //Unknown. But it's ok.
  ND_078_Child* cast2 = dynamic_cast<ND_078_Child*>(base1); //failed.
  ND_078_Child* cast3 = dynamic_cast<ND_078_Child*>(child2); //It's ok.
  int ret = 0;

  if(flag > 10) {
    ret += cast2->getValue2(); //@violation NULL_DEREF
  }
  else {
    ret += cast1->getValue2(); //It's ok.
    ret++;
  }

  delete base1;
  delete child2;
}

