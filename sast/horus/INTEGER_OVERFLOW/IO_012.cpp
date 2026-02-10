
/* IO_012 - unsigned int type, max */

#define UINT_MAX      0xffffffff    /* maximum unsigned int value */

void IO_012_check_suffix() {
  bool b = true;

  int i = 0; //int
  
  unsigned iu = 328u; //unsigned int
  
  unsigned biu = 329U; //unsigned int;
  
  long l = -128l; //long;
  
  long bl = -333L; //long;

  unsigned long ul = 553241ul; //unsigned long;

  unsigned long bul = 31123UL; //unsigned long;

  long long ll = -31ll; //long long

  long long bll = -1123123LL; //long long

  unsigned long long ull = 12345ull; //unsigned long long;

  unsigned long long bull = 91312412ULL; //unsigned long long;

  char ch = 'x'; //char;

  char hexc = 0xac; //int;

  short hexs = 0x4412; //int

  int hexi = 0xffff1352; //unsigned int
}


void IO_012_function2(int size){
  unsigned int data;
  data = 0;
  data = UINT_MAX;

  unsigned int result = data + 1;//@violation INTEGER_OVERFLOW
}
