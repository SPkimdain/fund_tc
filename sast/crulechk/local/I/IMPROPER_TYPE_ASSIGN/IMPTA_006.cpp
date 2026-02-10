//@checker IMPROPER_TYPE_ASSIGN

void IMPTA_006_function() {  
  unsigned int u32a = 0;
  unsigned int u32b = 3000; //It's ok.
  int s32a = 0;
  short s16a = 0;

  s16a = (5 * s32a * 10 / 8) & 0x80; //It's ok.

  unsigned short u16b = u32a; //@violation IMPROPER_TYPE_ASSIGN  
}

