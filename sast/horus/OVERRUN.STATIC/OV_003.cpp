
/* OV_003 - if branch1 */
void OV_003_function(int arg) {
  int value[5] = { 1, };
  if(arg == 10) {
    value[4] = 10;
  }
  else {
    value[10] = 10; //@violation OVERRUN.STATIC
  }  
}
