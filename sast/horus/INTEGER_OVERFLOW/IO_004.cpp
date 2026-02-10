#include <stdio.h>

/* IO_004 - fscanf1 */
void IO_004_function() {  
  char data = ' ';
  fscanf(stdin, "%c", &data);

  char result = data + 1; //@violation INTEGER_OVERFLOW
}

