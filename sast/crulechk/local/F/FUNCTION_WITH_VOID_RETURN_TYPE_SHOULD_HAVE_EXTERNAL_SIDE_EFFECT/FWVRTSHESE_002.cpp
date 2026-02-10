//@checker FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT

void FWVRTSHESE_002_function(int* buf, int* stream, int len) { //It's ok.
  for (int i = 0; i < len; i++) {
    buf[i] = stream[i]; 
  }
}

void FWVRTSHESE_002_function2(int* buf, int* stream, int len) { //It's ok.
  int* ptr = stream;

  *ptr = 10;
}


void FWVRTSHESE_002_function3(const int& x) { //It's ok.
  x++;
}

struct FWVRTSHESE_002_Struct {
  int arr[100];
};

void FWVRTSHESE_002_function4(FWVRTSHESE_002_Struct& obj) { //It's ok.
  obj.arr[5] = 10;
}

class FWVRTSHESE_002_Class {
public:
  int getValue() const {
    return value;
  }

  void setValue(int v) {
    value = v;
  }

private:
  int value;
};

void FWVRTSHESE_002_function5(FWVRTSHESE_002_Class obj) { //@violation FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT  
  obj.getValue(); 
}

void FWVRTSHESE_002_function6(FWVRTSHESE_002_Class& obj) { //It's ok.
  obj.setValue(10); 
}


void FWVRTSHESE_002_function7() { //It's ok.
  FWVRTSHESE_002_Class obj;
  obj.setValue(10);
}
