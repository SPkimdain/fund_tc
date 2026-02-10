#include <stdlib.h>
#include <memory.h>
#include <string.h>

/* OV_065 - readlink */

extern size_t readlink(const char* src, char* dst, size_t size);

void OV_065_function() {

  char buf[1024];
  size_t len = readlink("/usr/bin/perl", buf, sizeof(buf));
  
  buf[len] = '\0';  //@violation OVERRUN.STATIC

}
