//@checker PREFER_SPECIAL_MEMBER_AND_OVERLOADED_OP

void* memset(void* src, int val, unsigned size);

class PSMAOO_001_Class {
  int scalingFactor;
  int otherData;
  public:
    PSMAOO_001_Class(): scalingFactor(1) {}
  
  void set_other_data(int i);
  
  int f(int i) {
    return i / scalingFactor;
  }
}; //non-trivial class.

class PSMAOO_001_Class_Safe {
  int scalingFactor;
  int otherData;
public:  
  void set_other_data(int i);
  
  int f(int i) {
    return i / scalingFactor;
  }
}; //trivial class.


void PSMAOO_001_Function() {
  PSMAOO_001_Class obj;
  // ... Code that mutates c ...
  // Reinitialize c to its default state
  memset(&obj, 0, sizeof(PSMAOO_001_Class)); //@violation PREFER_SPECIAL_MEMBER_AND_OVERLOADED_OP
}


void PSMAOO_001_Function2() {
  PSMAOO_001_Class_Safe obj2;
  // ... Code that mutates c ...
  // Reinitialize c to its default state
  memset(&obj2, 0, sizeof(PSMAOO_001_Class_Safe)); //It's ok.
}
