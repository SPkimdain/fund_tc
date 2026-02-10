#include <math.h>

/* PMFE_003 - atan2 */

float PMFE_003_function(bool flag) {
  if(flag == true) {
    return 1.3F;
  }
  else {
    return 0.0F;
  }
}

void PMFE_003_function2() {
  float x = PMFE_003_function(true);
  float y = PMFE_003_function(true);

  double ret1 = atan2(x, y); //It's ok.

  y = PMFE_003_function(false);

  double ret2 = atan2(x, y); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}

