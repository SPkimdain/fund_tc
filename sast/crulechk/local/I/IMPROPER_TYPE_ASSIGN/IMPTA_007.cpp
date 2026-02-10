//@checker IMPROPER_TYPE_ASSIGN

void IMPTA_007_function() {  
  unsigned int u32a = 0;
  unsigned int u32b = 3000; //It's ok.

  short s16a = 10; //It's ok.
  int s32a = 10; //It's ok.
  unsigned short u16a = 5; //It's ok.

  unsigned int u32c = s16a; //@violation IMPROPER_TYPE_ASSIGN

  unsigned alpha = 10;

  alpha &= ~(1 + 2 + 4); //It's ok.
}

