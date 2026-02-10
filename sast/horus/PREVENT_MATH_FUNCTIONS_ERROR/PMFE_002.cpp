#include <math.h>

/* PMFE_002 - asin */

void PMFE_002_function() {
  double val = -0.3F;

  double x = asin(val); //It's ok.

  val = 5.3F;

  double y = asin(val); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}

