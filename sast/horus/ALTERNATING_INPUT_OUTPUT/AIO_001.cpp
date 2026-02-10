#include <stdio.h>

/* AIO_001 - simple case */

enum AIO_001_Tag { BUFFERSIZE = 32 };

extern void AIO_001_Initialize_data(char *data, size_t size);

void AIO_001_function(const char *file_name) {
  char data[BUFFERSIZE];
  char append_data[BUFFERSIZE];
  FILE *file;

  file = fopen(file_name, "a+");
  if(file == NULL) {
    /* Handle error */
  }

  AIO_001_Initialize_data(append_data, BUFFERSIZE);

  if(fwrite(append_data, 1, BUFFERSIZE, file) != BUFFERSIZE) {
    /* Handle error */
  }
  if(fread(data, 1, BUFFERSIZE, file) < BUFFERSIZE) { //@violation ALTERNATING_INPUT_OUTPUT
    /* Handle there not being data */
  }

  if(fclose(file) == EOF) {
    /* Handle error */
  }
}

void AIO_001_function2(const char *file_name) {
  char data[BUFFERSIZE];
  char append_data[BUFFERSIZE];
  FILE *file;

  file = fopen(file_name, "a+");
  if(file == NULL) {
    /* Handle error */
  }

  AIO_001_Initialize_data(append_data, BUFFERSIZE);

  if(fwrite(append_data, 1, BUFFERSIZE, file) != BUFFERSIZE) {
    /* Handle error */
  }

  if(fseek(file, 0L, SEEK_SET) != 0) {
    /* Handle error */
  }

  if(fread(data, 1, BUFFERSIZE, file) < BUFFERSIZE) { //It's ok.
    /* Handle there not being data */
  }

  if(fclose(file) == EOF) {
    /* Handle error */
  }
}
