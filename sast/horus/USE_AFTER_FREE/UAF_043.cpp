extern void SysFreeString(void* bstrString);

/* UAF_043 - 3rd party. */
char UAF_043_function(char* ptr, int flag) {
  SysFreeString(ptr);
  if(flag > 0) {
    return *ptr; //@violation USE_AFTER_FREE
  }
  else {
    return 0;
  }
}

