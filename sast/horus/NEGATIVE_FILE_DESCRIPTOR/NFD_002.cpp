#include <string.h>

/* NFD_002 - simple case */
#define O_WRONLY 128
#define O_CREAT 64

extern int open(char* filepath, int flags, int mode);
extern int write(int fd, char* filepath, int size);
extern int fsync(int fd);
extern void close(int fd);

int NFD_002_get() {
  return open("./test.txt", O_WRONLY | O_CREAT, 0644);
}

int NFD_002_getFD(int check) {
  if(check != 0) {
    return NFD_002_get();
  }
  return 0;
}

void NFD_002_function(int flag) {
  char* temp = "negative_file_descriptor";
  int fd = 0;

  fd = NFD_002_getFD(10);

  if(flag > 10) {
    if(fd < 0) {
      return;
    }
    
    fsync(fd); //It's ok.

  }
  else {
    fsync(fd); //@violation NEGATIVE_FILE_DESCRIPTOR
  }  

  close(fd);
}


