//@checker USE_FERROR_THAN_COMPARE_ERRNO

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int UFERRTCERR_001_function() {
  long num_long;

  if(scanf("%ld", &num_long) != 1) {
    return 2;
  }
  else if(ERANGE == errno) { //@violation USE_FERROR_THAN_COMPARE_ERRNO
    if(puts("number out of range\n") == -1) {
      return 1;
    }
  }
  return 0;
}

