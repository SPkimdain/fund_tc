#include <memory.h>

/* TOS_035 - unknown flow, from opus */
class TOS_035_Class {
public:
  void TOS_035_function1(char *p) {
    *(p + 1) = 'a';
  }

  void TOS_035_function2(int i)
  {
    char *p = 0;    
    memset(buf, 0, sizeof(buf));

    if(i){
      p = buf;
    }
    else {
      p = buf + 1; //This flow
    }

    TOS_035_function1(p);	//@violation TYPE_OVERRUN.STATIC  
  }

private:
  char buf[2];
};
