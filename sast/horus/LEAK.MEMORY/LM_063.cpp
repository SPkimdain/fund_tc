
/* LM_063 - Temporary object - call by value */

class LM_063_Class {
public:
  LM_063_Class(int x) : value(0) {
    value = new int;
    *value = x;
  }
  
  bool operator==(const LM_063_Class& rhs) const {
    return *value == *(rhs.value);
  }
  
  ~LM_063_Class() {
    if(value != 0) {
      delete value;
    }
  }
  
  int* value;
};

void LM_063_function1(int flag) {
  LM_063_Class obj(10);
} //It's ok.

int LM_063_function2(LM_063_Class obj) {
  return 0;
} //It's ok.

int LM_063_function3(LM_063_Class* obj) {
  int x = LM_063_function2(10); //implicit call ctor / dtor.
  return 0;
} //It's ok.

void LM_063_function4() {
  int* ptr = new int;
} //@violation LEAK.MEMORY
