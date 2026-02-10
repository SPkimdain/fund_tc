
/* UN_041 - uninit_03_02 from opus */
struct UN_041_Struct {
  int i;
  char c;
  long l;
};

int UN_041_function1(UN_041_Struct st, int flag) {
  if(flag == 1) {
    return st.i; // not defect
  }
  else if(flag == 2) {
    return st.l;
    //  defect (st.l)
  }
  else {
    return st.c; // not defect
  }
}

int UN_041_function2(int flag) {
  long x;
  UN_041_Struct st;
  st.i = 0;
  st.c = 1;
  x = UN_041_function1(st, flag);   //@violation UNINIT
  //  defect (st.l)
  return 0;
}
