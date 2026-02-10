
/* OV_004 - if branch2 */
void OV_004_function(int arg) {
  int value[4] = { 0, };
  int* ptr = 0;
  if(arg == 10) {
    ptr = (value + 1);
  }
  else {
    ptr = (value + 5);
  }

  *ptr = 10; //@violation OVERRUN.STATIC
}
