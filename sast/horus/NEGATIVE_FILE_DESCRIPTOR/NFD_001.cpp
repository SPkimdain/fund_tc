#include <string.h>

/* NFD_001 - simple case */
#define O_WRONLY 128
#define O_CREAT 64

extern int open(char* filepath, int flags, int mode);
extern int write(int fd, char* filepath, int size);
extern void close(int fd);

void NFD_001_function() {
  char* temp = "negative_file_descriptor";
  int fd = 0;

  fd = open("./test.txt", O_WRONLY | O_CREAT, 0644);
  
  write(fd, temp, strlen(temp)); //@violation NEGATIVE_FILE_DESCRIPTOR
  
  close(fd);
}

