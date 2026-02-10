
/* UN_052 - is_negative from opus */
int UN_052_function1(int number) {
  int sign;
  int *sign_flag = &sign;

  if(number > 0)
    *sign_flag = 1;
  else if(number < 0)
    *sign_flag = -1;

  return sign < 0; //@violation UNINIT
}
