#include <stdio.h>
#include <stdlib.h>

struct IO_018_Buffer {
  int kind;
  char arr[256];
};

extern int recv(int socket, char* buf, int size, int v);

int IO_018_get_size();
int IO_018_get_socket();
int IO_018_get_some_val();

/* IO_018 - taint3, socket, complex */
int IO_018_function1(int socket, char* buf, int size) {
  return recv(socket, buf, size, 0);
}

int IO_018_function2_wrap(char* buf) {
  if(buf == 0) {
    return 0;
  }
  int size = IO_018_get_size();
  
  int ret = IO_018_function1(IO_018_get_socket(), buf, size);
  
  return ret;
}

int& IO_018_dispatch(int& value, int& value2, bool flag) {
  if(flag == true) {
    return value;
  }
  else {
    return value2;
  }
}

int IO_018_function5(int flag, int flag2) {
  IO_018_Buffer buffer;
  buffer.kind = 0;  
  int data = 0;
  
  IO_018_function2_wrap(buffer.arr);
  
  switch(flag) {
  case 0:
    data = IO_018_get_some_val();
    break;
  case 1:
    return;  
  case 2:
    data = atoi(buffer.arr);
    break;
  default:
    break;
  }
  
  int x = 100;
  int& value = data;
  int& value2 = x;  
  
  if(flag2 == 10) {
    return IO_018_dispatch(value, value2, false) * 100; //It's ok.
  }
  else {
    return IO_018_dispatch(value, value2, true) * 100; //@violation INTEGER_OVERFLOW
  }
  
}
