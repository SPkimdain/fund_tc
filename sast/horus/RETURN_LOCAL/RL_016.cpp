
/* RL_016 - constructor, initializer list */
class RL_016_Class{
public:
  RL_016_Class(int* out) : value(100), ptr1(&value), ptr2(out) {}
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

extern char RL_016_function1();

int* RL_016_function2(int* param) {
  RL_016_Class obj(param);
  char check = RL_016_function1();
  check++;

  if(check == 5) {
    return obj.getPtr2(); //It's ok.
  }
  else { 
    return obj.getPtr1(); //@violation RETURN_LOCAL
  }
}

