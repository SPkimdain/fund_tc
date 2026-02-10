
/* RL_014 - Class field return using function call */
class RL_014_Class{
public:
  RL_014_Class(int& out) {
    value = 100;
    ptr1 = &value;
    ptr2 = &out;
  }

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

int* RL_014_function(int* param, int check, RL_014_Class* obj2) {
  RL_014_Class obj(*param);

  if(check > 10) {
    return obj.getPtr2(); //It's ok.
  }
  else if(check > 5) {
    return obj2->getPtr1(); //It's ok.    
  }
  else if(check == 3) {
    return obj2->getPtr2(); //It's ok.
  }
  else {
    return obj.getPtr1(); //@violation RETURN_LOCAL
  }
}

