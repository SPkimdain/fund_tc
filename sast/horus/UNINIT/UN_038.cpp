

/* UN_038 - uninit_02_03 from opus */
int UN_038_function1(int *ia)
{
  ia[0] = 0;
  ia[2] = 2;

  return 0;
}

int UN_038_function2(int *ia, int flag)
{
  if(flag == 1)
    return ia[0]; // not defect
  else if(flag == 2)
    return ia[1]; 
  else
    return ia[2]; // not defect
}

int UN_038_function3(int flag)
{
  int ia[3];

  UN_038_function1(ia);
  return UN_038_function2(ia, flag); //@violation UNINIT
}
