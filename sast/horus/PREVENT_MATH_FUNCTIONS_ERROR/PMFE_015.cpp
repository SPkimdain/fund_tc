/* PMFE_015 - remquo */

/* Since C++11 */
extern float remquo(float x, float y, int* z);

float PMFE_015_function(float arg) {
  int quo = 0.F;
  if(arg != 0) {    
    return remquo(10.3F, arg, &quo); //It's ok.
  }
  else {
    return remquo(33.4112F, arg, &quo); //@violation PREVENT_MATH_FUNCTIONS_ERROR
  }  
}

