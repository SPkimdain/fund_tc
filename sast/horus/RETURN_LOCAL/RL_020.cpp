
/* RL_020 - assert */
extern void assert(int expression);

char* RL_020_function(char* p, int flag, bool flag2) {
  char p2;
  if(flag2 == false) {
    char* ptr = flag > 10 ? p : &p2;
    assert(ptr != &p2);

    return ptr; //It's ok. ptr is not p2;
  }
  else {
    char* ptr2 = &p2;

    return ptr2; //@violation RETURN_LOCAL
  }
}
