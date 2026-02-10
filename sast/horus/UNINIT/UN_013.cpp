

/* UN_013 - for2 */
void UN_013_function(int value, int value2) {
  int p = 100;
  int p2;
  int* ptr = &p;
  int ret = 0;

  for(int i = 0; i < 2; i++) {
    
    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        ptr = &p2;
        ret += *ptr; //@violation UNINIT
        ptr = &p;
      }
    }
  }
}
