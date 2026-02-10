//@checker BAD_CALL.LIBRARY.MEMORY
typedef unsigned int size_t;

extern void* malloc_FB06(void *, size_t);
extern void realloc_FB06();

void BCLM_001_function(char * buf){        
  buf = (char *)malloc_FB06(buf, sizeof(char *) * 10); //@violation BAD_CALL.LIBRARY.MEMORY
  realloc_FB06(); //@violation BAD_CALL.LIBRARY.MEMORY
}

