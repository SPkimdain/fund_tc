

/* UN_037 - uninit_02_02 from opus */
int UN_037_function1(int *ia, int flag)
{
  if(flag == 1)
    return ia[0]; // not defect
  else if(flag == 2)
    return ia[1]; 
  else
    return ia[2]; // not defect
}

int UN_037_function2(int flag)
{
  int ia[3];
  ia[0] = 0;
  ia[2] = 2;

  return UN_037_function1(ia, flag); //@violation UNINIT
}
