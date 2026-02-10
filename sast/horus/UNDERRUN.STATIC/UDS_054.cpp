
/* UDS_054 - boundary index */
void UDS_054_function(int value) {
  int arr[10] = { 0, };
  if(value < 0) { //Wrong check.
    arr[value] = 10; //@violation UNDERRUN.STATIC
  }
}

