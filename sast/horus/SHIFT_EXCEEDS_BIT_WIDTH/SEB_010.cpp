
/* SEB_010 - array value */

void SEB_010_function2(int kind) {
  int arr[] = { 0, 2, 4, 32, 34 };
  unsigned int p = 10;

  switch(kind) {
  case 0:
    p = p << arr[0]; //It's ok.
    break;
  case 1:
    p = p << arr[1]; //It's ok.
    break;
  case 2:
    p = p << arr[2]; //It's ok.
    break;
  case 3:
    p = p << arr[3]; //@violation SHIFT_EXCEEDS_BIT_WIDTH  
    break;
  default:
    p = p << (arr[4] - 3); //It's ok.
    break;
  }

}

