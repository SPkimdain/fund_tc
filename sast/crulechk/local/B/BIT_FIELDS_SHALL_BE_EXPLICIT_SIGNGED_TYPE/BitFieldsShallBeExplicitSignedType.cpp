//@checker BIT_FIELDS_SHALL_BE_EXPLICIT_SIGNGED_TYPE



struct S
{
  wchar_t k : 2; //@violation BIT_FIELDS_SHALL_BE_EXPLICIT_SIGNGED_TYPE
  signed char d : 2;
  bool j : 2;
  char z : 2; //@violation BIT_FIELDS_SHALL_BE_EXPLICIT_SIGNGED_TYPE
  signed int a : 2;
  unsigned int  b : 2;
  char c : 2; //@violation BIT_FIELDS_SHALL_BE_EXPLICIT_SIGNGED_TYPE
  unsigned char e : 2;
  short f : 2; //@violation BIT_FIELDS_SHALL_BE_EXPLICIT_SIGNGED_TYPE
  signed short g : 2;
  unsigned short h : 2;
  int i: 2; //@violation BIT_FIELDS_SHALL_BE_EXPLICIT_SIGNGED_TYPE



};
