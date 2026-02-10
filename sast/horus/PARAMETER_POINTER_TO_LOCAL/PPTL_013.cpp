
/* PPTL_013 - singleton pattern */
class PPTL_013_Class {
public:
  static PPTL_013_Class& getInstance() {
    static PPTL_013_Class instance;
    return instance;
  }
  void setValue(int* x) {
    value = x;
  }

  int* getValue() {
    return value;
  }

private:
  PPTL_013_Class() {}
  ~PPTL_013_Class() {}

  int* value;
};

void PPTL_013_function(int check, int** out) {
  int y = 10000;
  int* x = new int();
  *x = 1000;
  PPTL_013_Class& obj = PPTL_013_Class::getInstance();
  obj.setValue(x);

  if(check == 10) {
    *out = obj.getValue(); //It's ok.
  }

  obj.setValue(&y);
  delete x;

  *out = obj.getValue();	//@violation PARAMETER_POINTER_TO_LOCAL

}


