#include <memory.h>

/* TUDS_035 - unknown flow, from opus */
class TUDS_035_Class {
public:
  void TUDS_035_function1(char *p) {
    *(p - 1) = 'a';
  }

  void TUDS_035_function2(int i)
  {
    char *p = 0;    
    memset(buf, 0, sizeof(buf));

    if(i){
      p = buf;  //This flow
    }
    else {
      p = buf + 1;
    }

    TUDS_035_function1(p);	//@violation TYPE_UNDERRUN.STATIC  
  }

private:
  char buf[2];
};
