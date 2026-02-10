
/* UN_018 - short circuit1 */
void UN_018_function() {
  int p1 = 1;
  int p2;
  int* ptr = &p1;
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  ret = *ptr; //ptr is pointed p1.

  ptr = 0;

  if(ptr = &p2) { 
    ret += *ptr; // @violation UNINIT
    x++;
  }
}

