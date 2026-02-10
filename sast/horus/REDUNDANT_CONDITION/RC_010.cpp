//@checker REDUNDANT_CONDITION

//RC_010 - false case. 

int RC_function_010(int flag, int a) {
  int b = 0;
  if(flag > 10) {
    b = 1;
  }
  else {
    a = 0;
  }

  if(a == 0) { //It's ok.
    return 1;
  }

  return 0;
}
