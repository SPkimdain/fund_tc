/* PPTL_015 - complex case */

struct PPTL_015_Struct {  
  short value[256];
};

struct PPTL_015_Struct2 {
  int x;
  int y;
  char kind;
  PPTL_015_Struct datas;
};

struct PPTL_015_Struct3 {
  PPTL_015_Struct3* next;
  PPTL_015_Struct2 obj;
};

short* PPTL_015_function(short* a, short* b, int flag) {
  if(flag > 10) {
    return a;
  }
  else {
    return b;
  }
}

void PPTL_015_function2(short** out, int flag, bool check1, bool check2){
  PPTL_015_Struct3 strVal;
  PPTL_015_Struct3 strVal2;
  strVal2.next = &strVal;
  strVal2.next->obj.datas.value[5] = 100;

  short* ptrSh = new short();

  short* data = PPTL_015_function(&(strVal2.next->obj.datas.value[5]), ptrSh, flag);
  
  if(check1 == true && check2 == false) {
    delete ptrSh;
    return;
  }
  else {    
    *out = data; //@violation PARAMETER_POINTER_TO_LOCAL
  }
  
  if(flag > 10) {
    delete ptrSh;
  }  
}

