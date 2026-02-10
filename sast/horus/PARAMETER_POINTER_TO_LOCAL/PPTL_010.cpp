
/* PPTL_010 - nested field return */

struct PPTL_010_Struct1 {
  int value;
  int value2;
};

struct PPTL_010_Struct2 {
  PPTL_010_Struct1* ptrObj;
  PPTL_010_Struct1 fldObj;
};

struct PPTL_010_Struct3 {
  int x;
  int y;
  PPTL_010_Struct2 pos;
};

extern PPTL_010_Struct1* PPTL_010_function1();


void PPTL_010_function2(PPTL_010_Struct3& param, int swt, int size, int** out) {
  PPTL_010_Struct3 local;
  PPTL_010_Struct1* obj = 0;

  for(int i = 0; i < size; i++) {
    if(swt == 10) {
      *out = &(param.pos.fldObj.value); //It's ok.
    }
  }

  switch(swt) {
  case 5:
    obj = PPTL_010_function1();
    *out = &(obj->value2); //It's ok.
    break;

  case 15:
    local.pos.ptrObj = PPTL_010_function1();
    *out = &(local.pos.ptrObj->value); //It's ok.
    break;

  case 20:
    *out = &(local.pos.fldObj.value2); //@violation PARAMETER_POINTER_TO_LOCAL
    break;

  default:
    break;
  }


  return;
}

