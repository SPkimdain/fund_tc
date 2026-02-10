
/* RL_018 - singleton pattern */
class RL_018_Class {
public:
  static RL_018_Class& getInstance() {
    static RL_018_Class instance;
    return instance;
  }
  void setValue(int* x) {
    value = x;
  }

  int* getValue() {
    return value;
  }

private:
  RL_018_Class() {}
  ~RL_018_Class() {}

  int* value;
};

int* RL_018_function(int check) {
  int y = 10000;
  int* x = new int();
  *x = 1000;
  RL_018_Class& obj = RL_018_Class::getInstance();
  obj.setValue(x);

  if(check == 10) {
    return obj.getValue(); //It's ok.
  }  

  obj.setValue(&y);
  delete x;

  return obj.getValue();	//@violation RETURN_LOCAL

}


