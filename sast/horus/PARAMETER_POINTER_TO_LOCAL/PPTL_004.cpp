
/* PPTL_004 - struct */
struct PPTL_004_struct {
  int val;
  int val2;
  int* ptr2;
};

void PPTL_004_function(PPTL_004_struct** obj, int val, int val2, int* ptr2, int flag){
  PPTL_004_struct str;
  str.val = val;
  str.val2 = val2;
  str.ptr2 = ptr2;


  if(flag > 10) {
    *obj = new PPTL_004_struct(); //It's ok.
  }
  else {
    *obj = &str; //@violation PARAMETER_POINTER_TO_LOCAL
  }
}
