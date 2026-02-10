#include <math.h>

/* PMFE_001 - acos */

void PMFE_001_function() {
  double x = acos(0.5F); //It's ok.

  double y = acos(-10.F); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}

