
/* IO_014 - unsigned int type, max2 */

#define UINT_MAX      0xffffffff    /* maximum unsigned int value */

void IO_014_function2(int size){
  unsigned int data;
  data = 0;
  data = UINT_MAX;

  unsigned int result = data * data; //@violation INTEGER_OVERFLOW  
}
