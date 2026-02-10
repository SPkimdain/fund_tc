#include <stdio.h>
#include <stdlib.h>

extern int recv(int socket, char* buf, int size, int v);

/* IO_016 - taint2, socket */
void IO_016_function2(int socket, int size){
  char buf[256];
  short data = 0;
  
  recv(socket, buf, size, 0); //taint.
  
  data = atoi(buf); //propagation

  short result = data * data; //@violation INTEGER_OVERFLOW
}
