/* NDMC_012 - compare nullptr */

extern int* NDMC_012_function1();

int NDMC_012_function2(int **p, int flag) {
  if(flag > 10) {
    return 1; //here.
  } 

  *p = NDMC_012_function1();  
  return 0;
}

void NDMC_012_function3(int *p2, int flag) {
  if(p2 == 0) {
    NDMC_012_function2(&p2, flag);
  }
  
  *p2 = 10; //@violation NULL_DEREF.MISSING_CHECK
}
