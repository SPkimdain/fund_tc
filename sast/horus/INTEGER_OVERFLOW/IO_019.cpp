
/* IO_019 - void* return type test */

//extern int Coverity_Tainted_Set(void);
extern void* Coverity_Tainted_Set(void);

int IO_019_function(void) {

  int len = (int)Coverity_Tainted_Set(); 

  int a = 10 * len;  //@violation INTEGER_OVERFLOW

  return 0;

}

