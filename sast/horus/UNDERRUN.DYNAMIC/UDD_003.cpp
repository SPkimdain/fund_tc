
/* UDD_003 - if branch1 */
void UDD_003_function(int arg) {
  int* value = new int[5];
  if(value == 0) {
    return;
  }

  if(arg == 10) {
    value[4] = 10;
  }
  else {
    value[-1] = 10; //@violation UNDERRUN.DYNAMIC
  }  

  delete[] value;
}
