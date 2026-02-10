#include <stdio.h>
#include <stdlib.h>

/* IO_008 - getenv */
char** IO_008_function() {
  const char* const lenstr = (char *)getenv("TABLE_SIZE");
  const unsigned int length = lenstr ? strtoul(lenstr, 0, 10) : 1;

  const unsigned table_size = length * sizeof(char *); //@violation INTEGER_OVERFLOW
  char** const table = (char **)malloc(table_size);

  if(table == 0) {
    return 0;   /* indicate error to caller */
  }

  /* initialize table... */
  return table;
}

