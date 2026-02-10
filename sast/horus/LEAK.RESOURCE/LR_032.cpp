
extern void SQLAllocHandle(int type, void *input, int  *handle);
extern void SQLFreeHandle(int type, int handle);

/* LR_032 - 3rd party & call by reference scaffold. */
int LR_032_function(int type, void* input, int flag){
  int handle = 0;
  int ret = 0;

  /* SQLAllocHandle use 'call by reference' return value. */
  SQLAllocHandle(type, input, &handle);
  if(flag > 10) {
    SQLFreeHandle(type, handle);
    ret++;
  }
  else {
    ret += 10;
  }
  
  return ret;
} //@violation LEAK.RESOURCE

