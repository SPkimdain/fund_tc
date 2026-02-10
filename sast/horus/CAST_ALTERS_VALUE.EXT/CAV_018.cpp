/* cpp + argument */

class CAV_018_Class {
public:
  void CAV_018_doSomething(short value);
};

void CAV_018_Class::CAV_018_doSomething(short value) {
  char ch = 0;
  ch = value;  
}

void CAV_018_function() {
  CAV_018_Class obj;
  short x = -12000;
  obj.CAV_018_doSomething(x); //@violation CAST_ALTERS_VALUE.EXT
}

