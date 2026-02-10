
/* IO_020 - veriserve case 0215 */
#define X 8800
#define Y 4400
#define Z 2200
#define W 1100



static float IO_020_function_get_float(int a) {
  float ret;
  switch(a) {
  default:               
  case 1: 
    ret = X; 
    break;               
  case 2: 
    ret = Y; 
    break;               
  case 3: 
    ret = Z; 
    break;               
  case 4: 
    ret = W; 
    break;
  }

  return ret;
}


static float IO_020_function1(int a) {
  float b = IO_020_function_get_float(a) * 1000000.0; //INTEGER_OVERFLOW(The result value can overflow by the operation 8800 * 1000000.)

  return b;
}

void IO_020_function2(int size){
  int si3 = 2147483645;

  int result2 = si3 + 3; //@violation INTEGER_OVERFLOW
}



