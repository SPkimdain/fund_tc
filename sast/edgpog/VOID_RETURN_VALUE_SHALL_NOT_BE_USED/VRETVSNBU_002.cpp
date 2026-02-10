//@checker VOID_RETURN_VALUE_SHALL_NOT_BE_USED

void VRETVSNBU_002_function() {
  int x = 0;
  x++;
  x++;
  x += 10;

  return;
}


void VRETVSNBU_002_caller() {

  int wtf = VRETVSNBU_002_function(); //@violation VOID_RETURN_VALUE_SHALL_NOT_BE_USED


  VRETVSNBU_002_function(); //It's ok.
}
