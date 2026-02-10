/* PMFE_014 - remainer */

/* Since C++11 */
extern double remainder(double x, double y);

double PMFE_014_Var;

void PMFE_014_function1(double value) {
  PMFE_014_Var = value;
}

double PMFE_014_function2() {
  int* ptr = 0;
  double value = 5.0F;
  PMFE_014_function1(value);

  double ret = remainder(105.42323, PMFE_014_Var - value); //@violation PREVENT_MATH_FUNCTIONS_ERROR

  return ret;
}

