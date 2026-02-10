
/* UN_045 - uninit_04_02 from opus */
struct UN_045_Struct1 {
  int i;
  char c;
  long l;
};

struct UN_045_Struct2 {
  UN_045_Struct1 st_sub;
};

int UN_045_function1(UN_045_Struct2 st, int flag) {
  if(flag == 1) {
    return st.st_sub.i; // not defect
  }
  else if(flag == 2) {
    return st.st_sub.l; 
    //  defect (st.st_sub.l)
  }
  else {
    return st.st_sub.c; // not defect
  }
}

int UN_045_function2(int flag) {
  long x;
  UN_045_Struct2 st;
  st.st_sub.i = 0;
  st.st_sub.c = 1;
  x = UN_045_function1(st, flag); //@violation UNINIT
  // defect (st.st_sub.l)
  return 0;
}
