#include <math.h>

/* PMFE_011 - pow2 */

double PMFE_011_function(double x, double y) {
  double ret = pow(x, y);

  return ret;
}

double PMFE_011_function2(double x, double y) {
  return PMFE_011_function(x, y);
}

void PMFE_011_function3(int flag) {
  double val = -0.55F;
  switch(flag) {
  case 0:
    PMFE_011_function2(0.0F, 2); //It's ok.
    break;
  case 1:
    PMFE_011_function2(0.F, 4.5F); //It's ok.
    break;
  case 2:
    PMFE_011_function2(0.F, val); //@violation PREVENT_MATH_FUNCTIONS_ERROR
    break;
  default:
    break;
  }

}

