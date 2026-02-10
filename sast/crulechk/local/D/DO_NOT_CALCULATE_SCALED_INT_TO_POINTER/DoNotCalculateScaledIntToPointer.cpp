//@checker DO_NOT_CALCULATE_SCALED_INT_TO_POINTER
#include <iostream>

enum { INTBUFSIZE = 80 };

extern int getdata(void);
int buf[INTBUFSIZE];

typedef struct trap {
  int a;
  int b;
} Trap;

int DNCSITP_001_function(void) {
  int *buf_ptr = buf + sizeof(int); //@violation DO_NOT_CALCULATE_SCALED_INT_TO_POINTER
  Trap trap;
  Trap *_trap = &trap;
  int boom = 0;
  boom = boom + sizeof(int);
  _trap += sizeof(Trap); //@violation DO_NOT_CALCULATE_SCALED_INT_TO_POINTER
  buf_ptr = (((buf + sizeof(buf)))); //@violation DO_NOT_CALCULATE_SCALED_INT_TO_POINTER
  while(buf_ptr < (buf + sizeof(buf))) { //@violation DO_NOT_CALCULATE_SCALED_INT_TO_POINTER
    *buf_ptr++ = 1;
  }
  return 0;
}
