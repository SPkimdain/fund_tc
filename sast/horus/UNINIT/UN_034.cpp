#pragma warning(disable : 4700)

/* UN_034 - uninit_01_03 from opus */
extern int UN_034_function1(int *p);

int UN_034_function2(int flag)
{
  int i;
  int buf[100];

  UN_034_function1(buf);

  // defect (buf)
  return buf[i]; //@violation UNINIT
}
