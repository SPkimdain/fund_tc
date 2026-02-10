
/* UN_046 - uninit_04_03 from opus */
struct UN_046_Struct1 {
  int i;
  char c;
  long l;
};

struct UN_046_Struct2 {
  UN_046_Struct1 st_sub;
};


int UN_046_function1(UN_046_Struct2 st, int flag)
{
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

int UN_046_function2(UN_046_Struct2 st, int flag) {
  return UN_046_function1(st, flag);
}

int UN_046_function3(UN_046_Struct2 st, int flag) {
  return UN_046_function2(st, flag);
}

int UN_046_function4(int flag) {
  long x;
  UN_046_Struct2 st;
  st.st_sub.i = 0;
  st.st_sub.c = 1;
  x = UN_046_function3(st, flag); //@violation UNINIT
  //defect (st.st_sub.l)
  
  return 0;
}

