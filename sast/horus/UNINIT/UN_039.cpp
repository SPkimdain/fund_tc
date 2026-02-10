
/* UN_039 - uninit_02_04 from opus */
int UN_039_function1(int *ia, int flag)
{
  if(flag==1)
    return ia[0]; // not defect
  else if(flag==2)
    return ia[1]; 
  else
    return ia[2]; // not defect
}

int UN_039_function2(int *ia, int flag)
{
  return UN_039_function1(ia, flag);
}

int UN_039_function3(int *ia, int flag)
{
  return UN_039_function2(ia, flag);
}

int UN_039_function4(int flag)
{
    int ia[3];
    ia[0] = 0;
    ia[2] = 2;
    
    return UN_039_function3(ia, flag); //@violation UNINIT
}

