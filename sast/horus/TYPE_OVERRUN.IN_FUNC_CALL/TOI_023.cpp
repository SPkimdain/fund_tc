#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* TYPE_OVERRUN.IN_FUNC_CALL */

struct TOI_023_regex {
  int flags;
  unsigned int sz;
  char re[1];
};

struct TOI_023_buffer
{
  unsigned int allocated;
  unsigned int length;
  char *b;
};

void TOI_023_panic(char *str){
  exit(4);
}

void* TOI_023_ck_malloc(unsigned int size) {
  void *ret = calloc(1, size ? size : 1);
  if (!ret) {
    TOI_023_panic("couldn't allocate memory");
  }
  return ret;
}

void* TOI_023_compile_TOI_023_regex(struct TOI_023_buffer *b) {
  unsigned int re_len;
  struct TOI_023_regex *new_TOI_023_regex;
  
  if(b->length == 0) return 0;

  re_len = b->length;

  new_TOI_023_regex = (struct TOI_023_regex *) TOI_023_ck_malloc(sizeof (struct TOI_023_regex) + re_len - 1);

  memcpy(new_TOI_023_regex->re, b->b, re_len); //It's ok.

  return new_TOI_023_regex;
}

struct TOI_023_Class {
  char dst[20];
};

void TOI_023_dummy() {
    TOI_023_Class obj; 
    memset(obj.dst, 20, 50); //@violation TYPE_OVERRUN.IN_FUNC_CALL
}
