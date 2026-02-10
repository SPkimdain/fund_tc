
/* RL_015 - class return */
class RL_015_Class{
public:
  RL_015_Class() {
    value = 100;
    ptr1 = &value;
    ptr2 = 0;
  }

private:
  int value;
  int* ptr1;
  int* ptr2;
};

RL_015_Class RL_015_function1() {
  RL_015_Class local;  
  return local; //It's ok. copy constructor.
}

RL_015_Class& RL_015_function2(RL_015_Class& objOut, int swt) {
  RL_015_Class obj1;
  RL_015_Class* obj2 = &objOut;

  if(swt > 10) {
    return objOut; //It's ok.
  }
  else if(swt > 5) {
    return *obj2; //It's ok.
  }
  else {
    return obj1; //@violation RETURN_LOCAL
  }
}

