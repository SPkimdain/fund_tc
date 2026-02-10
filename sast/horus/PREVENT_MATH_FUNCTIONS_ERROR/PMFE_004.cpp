/* PMFE_004 - acosh */

/* Since C++11 */
extern float acosh(float x);

void PMFE_004_function(int flag) {
  float x = 1.0F;

  float ret = acosh(x); //It's ok.

  switch(flag) {
  case 0:
  case 1:
    x = 0.3F;
    break;
  default:
    break;
  }

  float ret2 = acosh(x); //@violation PREVENT_MATH_FUNCTIONS_ERROR

}

