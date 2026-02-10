#include <stdio.h>
#include <stdlib.h>

/* IU_010 - getenv */
char** IU_010_function(int size) {
  const char* const offset = (char *)getenv("TABLE_SIZE");
  const unsigned int off = offset ? strtoul(offset, 0, 10) : 1;

  unsigned table_size = size * sizeof(char *); 
  table_size -= off; //@violation INTEGER_UNDERFLOW
  char** const table = (char **)malloc(table_size);

  if(table == 0) {
    return 0;   /* indicate error to caller */
  }

  /* initialize table... */
  return table;
}

