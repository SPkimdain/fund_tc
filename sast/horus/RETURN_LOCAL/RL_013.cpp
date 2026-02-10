
/* RL_013 - nested field return */

struct RL_013_Struct1 {
  int value;
  int value2;
};

struct RL_013_Struct2 {
  RL_013_Struct1* ptrObj;
  RL_013_Struct1 fldObj;
};

struct RL_013_Struct3 {
  int x;
  int y;
  RL_013_Struct2 pos;
};

extern RL_013_Struct1* RL_013_function1();


int* RL_013_function2(RL_013_Struct3& param, int swt, int size) {
  RL_013_Struct3 local;
  RL_013_Struct1* obj = 0;

  for(int i = 0; i < size; i++) {
    if(swt == 10) {
      return &(param.pos.fldObj.value); //It's ok.
    }
  }

  switch(swt) {
  case 5:
    obj = RL_013_function1();
    return &(obj->value2); //It's ok.

  case 15:
    local.pos.ptrObj = RL_013_function1();
    return &(local.pos.ptrObj->value); //It's ok.

  case 20:
    return &(local.pos.fldObj.value2); //@violation RETURN_LOCAL

  default:
    break;
  }


  return 0; 
}

