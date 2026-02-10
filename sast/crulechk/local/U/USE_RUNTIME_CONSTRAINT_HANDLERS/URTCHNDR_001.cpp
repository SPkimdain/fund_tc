//@checker USE_RUNTIME_CONSTRAINT_HANDLERS
extern int strcpy_s(char* dst, int size, const char* src);

int URTCHNDR_001_function(char *dst1, unsigned int size) {
  char src1[100] = "hello";
  if (strcpy_s(dst1, size, src1) != 0) { //@violation USE_RUNTIME_CONSTRAINT_HANDLERS
    return -1;
  }
  /* ... */
  return 0;
}

