#include <stdio.h>
#include <stdlib.h>

/* IO_009 - getenv, constraint */
char** IO_009_function(int flag) {
  const char* const lenstr = (char *)getenv("TABLE_SIZE");
  const unsigned char length = lenstr ? strtoul(lenstr, 0, 10) : 1;
  
  if(flag > 10) {
    if(length < 255) {
      const unsigned table_size = length * sizeof(char *); //It's ok.
      char** const table = (char **)malloc(table_size);

      if(table == 0) {
        return 0;   /* indicate error to caller */
      }

      /* initialize table... */
      return table;
    }
  }
  else {
    const unsigned table_size = length * sizeof(char *); //@violation INTEGER_OVERFLOW
    char** const table = (char **)malloc(table_size);

    if(table == 0) {
      return 0;   /* indicate error to caller */
    }

    /* initialize table... */
    return table;
  }

  return 0;
}

