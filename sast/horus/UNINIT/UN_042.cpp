
/* UN_042 - uninit_03_03 from opus */
struct UN_042_Struct {
  int i;
  char c;
  long l;
};

int UN_042_function1(UN_042_Struct st, int flag) {
  if(flag == 1)
    return st.i; // not defect
  else if(flag == 2)
    return st.l; 
  else
    return st.c; // not defect
}

int UN_042_function2(UN_042_Struct st, int flag) {
  return UN_042_function1(st, flag);
}

int UN_042_function3(UN_042_Struct st, int flag) {
  return UN_042_function2(st, flag);
}

int UN_042_function4(int flag) {
  long x;
  UN_042_Struct st;
  st.i = 0;
  st.c = 1;
  x = UN_042_function3(st, flag); //@violation UNINIT
  //defect (st.l)
  return 0;
}
