#include <math.h>

/* PMFE_010 - pow1 */

double PMFE_010_function(double x, double y) {
  double ret = pow(x, y);

  return ret;
}

void PMFE_010_function2(int flag) {
  double val = 0.F;
  switch(flag) {
  case 0:
    PMFE_010_function(3.5F, 2); //It's ok.
    break;
  case 1:
    PMFE_010_function(0.5F, 2.F); //It's ok.
    break;
  case 2:
    PMFE_010_function(val, -3.1); //@violation PREVENT_MATH_FUNCTIONS_ERROR
    break;
  default:
    break;
  }
  
}

