
/* CEFG_001 - simple test */

int CEFG_001_function1() { //Its' ok.
  int ret = 0;
  ret++;
  ret++;
  
  return 0;
}

void CEFG_001_function2() { //Its' ok.
  int retValue = CEFG_001_function1();  
}

/* No one called */
void CEFG_001_function3() { //@violation CALL_EVERY_FUNCTION_GLOBAL
  int reValue2 = CEFG_001_function1();
  
  CEFG_001_function2();
}
