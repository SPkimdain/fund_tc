//@checker REDUNDANT_CONDITION

//RC_011 - false case. 

int RC_function_011(int flag, int a) {
  int b = 0;
  if(flag > 10) {
    b = 1;
  }
  
  if(b == 1) {	//It's ok.
	a = 0;  
  }
  
  if(a == 0) { //It's ok.
    return 1;
  }

  return 0;
}
