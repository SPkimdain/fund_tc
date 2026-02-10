#include <stdio.h>

/* IU_006 - fscanf1 */
void IU_006_function() {
  char data = ' ';
  fscanf(stdin, "%c", &data);

  char result = data - 1; //@violation INTEGER_UNDERFLOW
}

