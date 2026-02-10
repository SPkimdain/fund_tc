

/* RL_010 - for2 */
int* RL_010_function(int value, int value2) {
  int p = 100;
  int* ptr = &p;
  int ret = 0;

  for(int i = 0; i < 2; i++) {
    if(value > 10) { 
      if(value2 > 5) { 
        return ptr; //@violation RETURN_LOCAL
      }
    }
  }

  return 0;
}
