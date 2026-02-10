#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <winsock.h>
#else

struct sockaddr {
  /* dummy for a library */
};

struct sockaddr_in {
  /* dummy for a library */
};

extern int connect(int sockfd, sockaddr* serv_addr, int addrlen);

#endif /* _WIN32 */


int RSRCI_001_function(){
  char *rPort = getenv("rPort");
  struct sockaddr_in serv_addr;
  int sockfd = 0;
  char buf[25];
  strncpy(buf, rPort, 25); 
  if(connect(sockfd,(struct sockaddr *)buf, sizeof(serv_addr)) < 0) { //@violation RESOURCE_INJECTION
    exit(1);
  }
  return 0;
}

