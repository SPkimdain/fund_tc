
/* RL_011 - short circuit */
int* RL_011_function(int& out, int flag) {
  int p = 20;
  int* ptr = &out;
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  if(flag > 10) {
    return ptr; //It's ok.
  }  
  
  ptr = &p;

  return ptr; //@violation RETURN_LOCAL
}
