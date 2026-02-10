/* PPTL_006 - field out2 */

struct PPTL_006_Struct{
  int* v;  
};

void PPTL_006_function(PPTL_006_Struct& obj, int flag){
  int y = 7;
  if(flag > 100) {
    obj.v = &y; //@violation PARAMETER_POINTER_TO_LOCAL
  }
}

