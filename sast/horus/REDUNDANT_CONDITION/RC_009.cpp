//@checker REDUNDANT_CONDITION

//RC_009 - simple case 

int RC_function_009(int flag, int a) {
  int b = 0;
  if(flag > 0) { //cond 1
    a = 10;
  }

  //cond 2
  if(b == 0) { //@violation REDUNDANT_CONDITION
    return 1;
  }

  //cond 3
  if(a == 10) { //It's ok.
    return 2;
  }

  return 0;
}
