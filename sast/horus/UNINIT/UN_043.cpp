

/* UN_043 - uninit_03_04 from opus */
struct UN_043_Struct {
  int i;
  char c;
  long l;
};

int UN_043_function1(UN_043_Struct *st, int flag)
{
  if(flag == 1) {
    return st->i; // not defect
  }
  else if(flag == 2) {
    return st->l; 
    //  defect (st->l)
  }
  else {
    return st->c; // not defect
  }
}

int UN_043_function2(UN_043_Struct *st)
{
  st->i = 0;
  st->c = 1;
  return 0;
}

int UN_043_function3(int flag)
{
  long x;
  UN_043_Struct st;
  UN_043_function2(&st);
  x = UN_043_function1(&st, flag); //@violation UNINIT
  // defect (st.l)
  return 0;
}
