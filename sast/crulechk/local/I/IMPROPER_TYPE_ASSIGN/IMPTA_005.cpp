//@checker IMPROPER_TYPE_ASSIGN

void IMPTA_005_function() {  
  unsigned int u32a = 0;
  unsigned int u32b = 3000; //It's ok.
  short s16a = 0;

  u32a += 10; //It's ok.
  s16a -= 3; //It's ok.

  u32a = (unsigned int)s16a; //It's ok.

  int s32b = 10000; //It's ok.
  int s32c = s32b; //It's ok.

  u32a = s16a; //@violation IMPROPER_TYPE_ASSIGN
}

