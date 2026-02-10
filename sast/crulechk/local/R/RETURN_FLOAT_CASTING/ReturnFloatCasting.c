// @checker RETURN_FLOAT_CASTING

int calcTest(int b){
	return b * 10;
}

float calcPercentage3(float value) {
  volatile float result;
 
  result = value * 0.1f;
 
  return result;
}


float calcPercentage(float value) {
  return (value * 0.1f);	//@violation RETURN_FLOAT_CASTING
}

double calcPercentage1(float value) {
  return (double)(value * 0.1f);
}

double calcPercentage2(float value) {
  return value * 0.1f;	//@violation RETURN_FLOAT_CASTING
}
 
void floatRoutine(void) {
  float value = 99.0f;
  long double percentage;
 
  percentage = calcPercentage(value);
}

