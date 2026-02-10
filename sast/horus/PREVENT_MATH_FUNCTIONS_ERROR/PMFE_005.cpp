#include <math.h>

/* PMFE_005 - atanh */

void PMFE_005_function() {
  double x = acos(0.5F); //It's ok.

  double y = acos(-10.F); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}

