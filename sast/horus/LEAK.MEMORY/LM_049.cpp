#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* LEAK.MEMORY */
struct LM_049_line {
  char *text;        /* Pointer to line allocated by malloc. */
  char *active;        /* Pointer to non-consumed part of text. */
  unsigned int length;    /* Length of text (or active, if used). */
  unsigned int alloc;        /* Allocated space for active. */
  int chomped;        /* Was a trailing newline dropped? */
  int mbstate[10];
};

void *LM_049_xmalloc(unsigned int n) {
  void *p = malloc(n);
  if(!p && n != 0) {
    exit(1);
  }
  return p;
}

void LM_049_line_init(LM_049_line* buf, LM_049_line* state, unsigned int size){
  buf->text = (char*) LM_049_xmalloc(size); //it's ok
  buf->active = buf->text;
  buf->alloc = size;
  buf->length = 0;
  buf->chomped = 1;
  
  if(state){
  }
  else {
    memset(&buf->mbstate, 0, sizeof (buf->mbstate));
  }
  
  return;
}

void LM_049_line_init2(int size){
  char *x = (char*)LM_049_xmalloc(size);
  
  return;
} //@violation LEAK.MEMORY
