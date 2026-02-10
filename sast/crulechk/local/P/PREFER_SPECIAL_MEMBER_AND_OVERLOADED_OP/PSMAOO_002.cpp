//@checker PREFER_SPECIAL_MEMBER_AND_OVERLOADED_OP

int memcmp(const void* src1, const void* src2, unsigned size);

class PSMAOO_002_Class {
  int i;
  public:
    virtual void f();
  // ...
};

class PSMAOO_002_Class_Safe {
public:
  void doSomething();
  
private:
  int x;
  short y;
};

void PSMAOO_002_function(PSMAOO_002_Class& c1, PSMAOO_002_Class& c2) {
  if (!memcmp(&c1, &c2, sizeof(PSMAOO_002_Class))) { //@violation PREFER_SPECIAL_MEMBER_AND_OVERLOADED_OP
    // ...
  }
  
}


void PSMAOO_002_function2(PSMAOO_002_Class_Safe& cs1, PSMAOO_002_Class_Safe& cs2) {
  if (!memcmp(&cs1, &cs2, sizeof(PSMAOO_002_Class_Safe))) { //It's ok.
    // ...
  }

}
