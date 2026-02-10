
/* RF_005 - struct example */


struct RF_005_struct{
  int val;
  int val2;
  int* ptr2;
};

RF_005_struct* RF_005_function(int val, int val2, int* ptr2){
  RF_005_struct* str = new RF_005_struct();
  str->val = val;
  str->val2 = val2;
  str->ptr2 = ptr2;

  delete str;

  return str; //@violation RETURN_FREE
}
