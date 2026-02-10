
/* PMFE_007 - log1p */

/* Since C++11 */
extern double log1p(double x);

void PMFE_007_function() {
  double x = log1p(-0.3F); //It's ok.

  double y = log1p(-1.0F); //It's ok.

  double z = log1p(-1.7F); //@violation PREVENT_MATH_FUNCTIONS_ERROR
}

