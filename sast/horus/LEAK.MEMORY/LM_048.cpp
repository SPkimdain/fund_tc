#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* LM_048 - false negative */

void* LM_048_xmalloc(size_t n) {
  void *p = malloc(n);
  if(!p) {
    exit(1);
  }
  return p;
}

void* LM_048_xzalloc(size_t s) {
  return memset(LM_048_xmalloc(s), 0, s); //It's ok.
}

void* LM_048_xzalloc2(size_t s) {
  void* ptr = LM_048_xmalloc(s);
  void* ret = memset(ptr, 0, s); //It's ok.
  return ptr;
}

void LM_048_leak(){
  void* value = LM_048_xmalloc(100);
  
  free(value); //It's ok.
  
  void* value2 = LM_048_xmalloc(200); 
} //@violation LEAK.MEMORY  

