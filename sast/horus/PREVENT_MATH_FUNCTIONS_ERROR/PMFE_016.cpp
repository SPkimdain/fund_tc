#include <math.h>

/* PMFE_016 - acos complex */
double PMFE_016_function1(double x) {
  return acos(x);
}

void PMFE_016_function2() {
  double ret = 0.0;
  PMFE_016_function1(1.0); //It's ok.

  PMFE_016_function1(-1.0); //It's ok.
  
  PMFE_016_function1(3.3); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}


