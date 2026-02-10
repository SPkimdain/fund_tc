
/* OV_057 - boundary index */
void OV_057_function(int value) {
  int arr[10] = { 0, };
  if(value > 10) { //Wrong check.
    arr[value] = 10; //@violation OVERRUN.STATIC
  }
}

