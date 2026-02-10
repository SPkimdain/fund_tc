
/* UCBO_001 - simple case */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <string.h>

#ifdef _WIN32

#include <winsock.h>

#else 

#include <sys/socket.h>
#include <arpa/inet.h>
#include <byteswap.h>
#include <unistd.h>

#endif /* _WIN32 */

unsigned int UCBO_001_function(int sock, int server) {
  int error = 0;
  unsigned int num = 0;
  if(recv(sock, (char*)(void *)&num, sizeof(num), 0) < (unsigned) sizeof(num)) {  
    error = 1;
  }

  return num; //@violation USE_CORRECT_BYTE_ORDERING
}

unsigned int UCBO_001_function2(int sock, int server) {
  int error = 0;
  unsigned int num = 0;
  if(recv(sock, (char*)(void *)&num, sizeof(num), 0) < (unsigned) sizeof(num)) {
    error = 1;
  }
  num = ntohl(num);  

  return num;
  
}

