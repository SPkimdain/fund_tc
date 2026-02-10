
/* ND_028 - singleton pattern */
class ND_028_Class {
public:
  static ND_028_Class& getInstance() {
    static ND_028_Class instance;
    return instance;
  }
  void setValue(int* x) {
    value = x;
  }

  void printValue() {
    *value = 10; 
  }

private:
  ND_028_Class() {}
  ~ND_028_Class() {}

  int* value;
};

void ND_028_function() {
  int* x = new int();
  *x = 1000;
  ND_028_Class& obj = ND_028_Class::getInstance();
  obj.setValue(x);
  
  obj.printValue(); //It's ok.

  obj.setValue(0);

  obj.printValue();	//@violation NULL_DEREF

  delete x;
}

