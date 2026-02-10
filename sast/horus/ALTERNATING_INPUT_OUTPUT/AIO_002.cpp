#include <stdio.h>

/* AIO_002 - simple case */

enum AIO_002_Tag { BUFFERSIZE = 32 };

extern void AIO_002_Initialize_data(char *data, size_t size);

void AIO_002_function(FILE* file) {
  char append_data[BUFFERSIZE];
  AIO_002_Initialize_data(append_data, BUFFERSIZE);

  if(fwrite(append_data, 1, BUFFERSIZE, file) != BUFFERSIZE) {
    /* Handle error */
  }
}

void AIO_002_function2(const char *file_name) {
  char data[BUFFERSIZE];
  char append_data[BUFFERSIZE];
  FILE *file;

  file = fopen(file_name, "a+");
  if(file == NULL) {
    /* Handle error */
  }

  AIO_002_function(file);
  
  if(fread(data, 1, BUFFERSIZE, file) < BUFFERSIZE) { //@violation ALTERNATING_INPUT_OUTPUT
    /* Handle there not being data */
  }

  if(fclose(file) == EOF) {
    /* Handle error */
  }
}
