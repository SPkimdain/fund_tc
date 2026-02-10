
/* TOBC_010 - trace value */
struct TOBC_010_Struct {
  char dst1[10];
  char dst2[4];
};

int TOBC_010_function1(int arg) {
  return ++arg;
}

void TOBC_010_function2(unsigned index) {
  char ch = 'a';
  TOBC_010_Struct obj;

  if(index < 4) { // [0, 3]
    index = TOBC_010_function1(index); // [1, 4]
    index = TOBC_010_function1(index); // [2, 5]    
    
    obj.dst1[index] = ch; //It's ok.

    obj.dst2[index] = ch; //@violation TYPE_OVERRUN.BAD_COND
  }
}


