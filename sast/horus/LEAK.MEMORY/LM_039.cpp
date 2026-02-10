
extern int LM_039_function1();

/* LM_039 - for / break */
void LM_039_function2() {

  int n = 8;
  int k = 0;

  for (int i = 0; i < n; i++) {
    double *err = new double[n];

    for (int j = 0; j < 10; ++j) {
      k += j;
    }

    if(LM_039_function1() <= 4) {
      break;
    }
  } 
} //@violation LEAK.MEMORY
