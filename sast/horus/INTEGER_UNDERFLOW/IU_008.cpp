#include <stdio.h>
#include <stdlib.h>

/* IU_008 - fscanf3 */
void IU_008_function() {
  char data = ' ';
  fscanf(stdin, "%c", &data);

  char result = data - 5; //@violation INTEGER_UNDERFLOW
}

