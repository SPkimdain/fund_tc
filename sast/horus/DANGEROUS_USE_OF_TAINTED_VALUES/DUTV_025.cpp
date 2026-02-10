#include <stdio.h>

/* DUTV_025 - taint generate / call by reference case1 */

extern int fscanf(FILE* fp, char* format, ...);
extern char* hw_getfile(FILE* fp);
extern void hw_memcpy(char* dst, char* src, int size);


int DUTV_025_function(char* src, int len) {
  char s[20] = {0}, *p = 0;

  int a = 0, b = 9, c = 0, d = 6;

  FILE *fp = 0;

  hw_getfile(fp);

  fscanf(fp, "%d %d %d", &b, &c, &d); // taint propagate from fp to b, c, d

  // sink point has configure by checker option, but not occurred
  hw_memcpy(s, "hello world", b); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
  return 0;

}

