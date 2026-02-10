#pragma warning(disable : 4700)

#include <memory.h>

/* UN_035 - uninit_01_04, from opus */
void UN_035_function1(char *p) {
  // if i is 0.
  p[0] = 'a'; // UNINIT
  
}

int UN_035_function1(int& flag)
{
  int i;
  i = flag + 99;   // UNINIT
  return i;
}

int UN_035_function2(int& flag)
{
  return UN_035_function1(flag);
}

int UN_035_function3(int& flag)
{
  return UN_035_function2(flag);
}

int UN_035_function4(int flag)
{
  int i;

  if(flag)
    return UN_035_function3(i); //@violation UNINIT
  else
    return -1;
}


