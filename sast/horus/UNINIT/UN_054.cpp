#include <iostream>

using namespace std;

/* UN_054 - missing base constructor */
class UN_054_Base {
public:
  UN_054_Base() : value(0) {
  }

  UN_054_Base(int x) { /* Missing value initialization. */
    x = 0; //Wrong assign.
  }

  int getValue() { return value; }

private:
  int value;
};

class UN_054_Derived1 : public UN_054_Base {
public:
  UN_054_Derived1() : UN_054_Base(), value2(0) {}

private:
  char value2;
};

class UN_054_Derived2 : public UN_054_Base {
public:
  UN_054_Derived2() : UN_054_Base(10), value3(0.F) {} //Calling base ctor with argument.
private:
  float value3;
};

class UN_054_Container {
public:
  UN_054_Container() : obj1(), obj2() {}

  UN_054_Derived1& getObject1() {
    return obj1;
  }

  UN_054_Derived2& getObject2() {
    return obj2;
  }

private:
  UN_054_Derived1 obj1;
  UN_054_Derived2 obj2;
};

int UN_054_function1(UN_054_Derived2& obj2) {
  static int count = 0;

  if(count > 10) {
    return 0;
  }
  else {
    count++;
    cout << obj2.getValue();
  }

  return count;
}


void UN_054_function2(int checksum, UN_054_Derived2* obj2) {
  if(obj2 != 0 && checksum > 100) {
    int ret = 0;
    
    ret = UN_054_function1(*obj2);

  }
}

void UN_054_function3(int anyVal, int flag, int flag2) {
  UN_054_Container cont;

  UN_054_Derived1& obj = cont.getObject1();

  int min = obj.getValue(); //It's ok.
  int iter = 100;
  int sum = 0;

  do {
    sum += anyVal;
    
    anyVal++;
    if(anyVal > 100) {
      anyVal = 0;
    }

    iter--;
  } while(iter != min); 


  if(flag > 0 && sum > 10000 && flag2 == 1) {
    flag = 20;
    flag2 = flag + 30;

    UN_054_function2(101, &(cont.getObject2())); //@violation UNINIT
    
  }
}
