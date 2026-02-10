#include <new>

/* UN_047 - uninit_04_04 */
struct UN_047_Struct1 {
  int i;
  char c;
  long l;
};

struct UN_047_Struct2 {
  UN_047_Struct1 st_sub;
};

int UN_047_function1(UN_047_Struct2 *st, int flag) {
  if(flag == 1) {
    return st->st_sub.i; // not defect
  }
  else if(flag == 2) {
    return st->st_sub.l; 
    //defect (st->st_sub.l)
  }
  else {
    return st->st_sub.c; // not defect
  }
}

int UN_047_function2(UN_047_Struct2 *st) {
  st->st_sub.i = 0;
  st->st_sub.c = 1;
  return 0;
}

int UN_047_function3(int flag) {
  long x;
  UN_047_Struct2 st;
  UN_047_function2(&st);
  x = UN_047_function1(&st, flag); //@violation UNINIT  
  //defect (st.st_sub.l)
  return 0;
}

