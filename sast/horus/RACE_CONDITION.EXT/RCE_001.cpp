// For windows

#include <stdio.h>
#include <sys/stat.h>

#define _S_IREAD 0x0100  

#ifdef _WIN32

#include <io.h>

#else
#endif

void RCE_001_function() {
  const char *file_name = "a.txt";
  FILE *f_ptr;
  /* initialize file_name */
  f_ptr = fopen(file_name, "w");

  if (f_ptr == NULL)  {
    return;
  }

  if (chmod(file_name, _S_IREAD) == -1) {  //@violation RACE_CONDITION.EXT
    /* Handle error */
  }

  fclose(f_ptr);
}
    