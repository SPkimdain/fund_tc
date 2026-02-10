
/* RF_010 - class return */
class RF_010_Class{
public:
  RF_010_Class() {
    value = 100;
    ptr1 = &value;
    ptr2 = 0;
  }

private:
  int value;
  int* ptr1;
  int* ptr2;
};

RF_010_Class RF_010_function1() {
  RF_010_Class local;
  return local; //It's ok. copy constructor.
}

RF_010_Class& RF_010_function2(RF_010_Class& objOut, int swt) {
  RF_010_Class* obj1 = new RF_010_Class();
  RF_010_Class* obj2 = &objOut;

  delete obj1;

  if(swt > 10) {
    return objOut; //It's ok.
  }
  else if(swt > 5) {
    return *obj2; //It's ok.
  }
  else {
    return *obj1; //@violation RETURN_FREE
  }
}

