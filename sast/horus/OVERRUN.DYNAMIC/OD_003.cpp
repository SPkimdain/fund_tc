
/* OD_003 - if branch1 */
void OD_003_function(int arg) {
  int* value = new int[5];
  if(value == 0) {
    return;
  }

  if(arg == 10) {
    value[4] = 10;
  }
  else {
    value[10] = 10; //@violation OVERRUN.DYNAMIC
  }  

  delete[] value;
}
