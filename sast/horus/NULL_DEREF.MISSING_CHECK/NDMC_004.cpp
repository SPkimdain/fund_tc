

/* NDMC_004 - controlw flow - always nullptr. */

struct NDMC_004_Struct {
  int x;
  int y;
};

void NDMC_004_function1(NDMC_004_Struct*& t) {
  if(t != 0) {  
    t = 0;
  }
}

void NDMC_004_function2(NDMC_004_Struct* test) {
  NDMC_004_function1(test);

  if(test != 0) {
    test->x = 10; //It's ok.
    int *x = 0;
    *x = 10;
  }  
}

void NDMC_004_function3(NDMC_004_Struct* test) {
  if(test != 0) {
    test->x = 10;
  }
  
  test->y = 20; //@violation NULL_DEREF.MISSING_CHECK
}

