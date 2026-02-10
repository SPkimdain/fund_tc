#include <stdio.h>

/* DUTV_026 - taint generate / call by reference case1 */

extern int fscanf(FILE* fp, char* format, ...);
extern char* hw_getfile(FILE* fp);
extern void hw_memcpy(char* dst, char* src, int size);


int DUTV_026_function(char* src, int len, int flag, FILE *fp) {
  char s[20] = { 0 }, *p = 0;

  int a = 0, b = 9, c = 0, d = 6;

  hw_getfile(fp);

  if(flag > 10) {
    fscanf(fp, "%d %d %d", &b, &c, &d); // taint propagate from fp to b, c, d
  }

  // sink point has configure by checker option, but not occurred
  
  if(flag > 10) {
    hw_memcpy(s, "hello world", d); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  }
  else {
    hw_memcpy(s, "hello world", d); //It's ok.
  }
  return 0;
}

