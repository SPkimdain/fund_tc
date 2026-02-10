
/* UDD_018 - short circuit1 */
void UDD_018_function() {
  int* p = new int[5];
  if(p == 0) {
    return;
  }
  int* ptr = p;
  int x = 10;
  int compareValue = 20;
  int ret = 0;
  
  ret = *ptr; //It's ok.
  
  ptr = p;
  if(compareValue > *(ptr - 7)) { // @violation UNDERRUN.DYNAMIC
    x++;
  }

  delete[] p;
}

