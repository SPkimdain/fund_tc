
/* PPTL_011 - constructor, initializer list */
class PPTL_011_Class{
public:
  PPTL_011_Class(int* out) : value(100), ptr1(&value), ptr2(out) {}
  int* getPtr1() {
    return ptr1;
  }

  int* getPtr2() {
    return ptr2;
  }

private:
  int value;
  int* ptr1;
  int* ptr2;
};

extern char PPTL_011_function1();

void PPTL_011_function2(int* param, int** out) {
  PPTL_011_Class obj(param);
  char check = PPTL_011_function1();
  check++;

  if(check == 5) {
    *out = obj.getPtr2(); //It's ok.
  }
  else {
    *out = obj.getPtr1(); //@violation PARAMETER_POINTER_TO_LOCAL
  }
}

