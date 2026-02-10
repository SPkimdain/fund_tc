
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

#endif /* _WIN32 */

/* RSRCI_002 - simple case2 */

extern int connect(int sockfd, sockaddr* serv_addr, int addrlen);

int RSRCI_002_function3(){
  char *rPort = getenv("rPort");
  struct sockaddr_in serv_addr;
  int sockfd = 0;
  char buf[25];
  
  strncpy(buf, rPort, 25);

  char* complex = buf;
  
  if(connect(sockfd, (struct sockaddr *)complex, sizeof(serv_addr)) < 0) { //@violation RESOURCE_INJECTION
    exit(1);
  }
  return 0;
}

