
/* UN_036 - uninit_02_01 from opus */
int UN_036_function(int flag)
{
  int ia[3];
  ia[0] = 0;
  ia[2] = 2;

  if(flag == 1)
    return ia[0]; // not defect
  else if(flag == 2)
    return ia[1]; // @violation UNINIT
  else
    return ia[2]; // not defect
}
