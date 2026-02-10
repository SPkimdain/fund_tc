/* NDMC_011 - global variable. */

int* NDMC_011_gvar = 0;

extern int* NDMC_011_function1();

void NDMC_011_function2(int *p2) {
  if(NDMC_011_gvar == 0) {
    NDMC_011_gvar = new int(10);
    
    if(p2 == 0) {
      int* x = NDMC_011_function1();
      (*x)++;
    }
    
    *NDMC_011_gvar = 10; //It's ok.
  }	
}

void NDMC_011_function3(int *p2) {
  if(p2 == 0) {
    *p2 = 10; //@violation NULL_DEREF.MISSING_CHECK
  }
}
