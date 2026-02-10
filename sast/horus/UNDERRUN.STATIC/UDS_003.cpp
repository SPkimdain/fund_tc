
/* UDS_003 - if branch1 */
void UDS_003_function(int arg) {
  int value[5] = { 1, };
  if(arg == 10) {
    value[4] = 10;
  }
  else {
    value[-5] = 10; //@violation UNDERRUN.STATIC
  }  
}
