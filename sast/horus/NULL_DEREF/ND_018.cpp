
/* ND_018 - short circuit1 */
void ND_018_function() {
  int p = 20;
  int* ptr = &p;
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  ret = *ptr; //ptr is not 0.
  
  ptr = 0;

  if(compareValue > *ptr) { // @violation NULL_DEREF
    x++;
  }
}

