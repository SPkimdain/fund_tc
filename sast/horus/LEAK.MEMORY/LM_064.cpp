
/* LM_064 - Temporary object - call by value */

class LM_064_Class {
public:
  LM_064_Class(int x) : value(0) {
    value = new int;
    *value = x;
  }
  
  bool operator==(const LM_064_Class& rhs) const {
    return *value == *(rhs.value);
  }
  
  ~LM_064_Class() {
    if(value != 0) {
      delete value;
    }
  }
  
  int* value;
};

void LM_064_function1(int flag) {
  LM_064_Class obj(10);
} //It's ok.

int LM_064_function2(LM_064_Class obj, LM_064_Class obj2) {
  return 0;
} //It's ok.

int LM_064_function3(LM_064_Class* obj) {
  int x = LM_064_function2(10, 20); //implicit call ctor / dtor * 2
  return 0;
} //It's ok.

void LM_064_function4() {
  int* ptr = new int;
} //@violation LEAK.MEMORY
