
/* LM_062 - Temporary object. */

class LM_062_Class {
public:
  LM_062_Class(int x) : value(0) {
    value = new int;
    *value = x;
  }
  
  bool operator==(const LM_062_Class& rhs) const {
    return *value == *(rhs.value);
  }
  
  ~LM_062_Class() {
    if(value != 0) {
      delete value;
    }
  }
  
  int* value;
};

void LM_062_function1(int flag) {
  LM_062_Class obj(10);
} //It's ok.

int LM_062_function2(LM_062_Class* obj) {
  if(*obj == LM_062_Class(20)) {
    return 1;    
  }
  else {
    return 0;
  }  
} //It's ok.

int LM_062_function3(LM_062_Class* obj) {
  *obj = LM_062_Class(20);
  return 0;
} //It's ok.

void LM_062_function4() {
  int* ptr = new int;
} //@violation LEAK.MEMORY
