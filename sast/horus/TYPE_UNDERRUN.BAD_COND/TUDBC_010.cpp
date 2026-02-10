
/* TUDBC_010 - trace value */
struct TUDBC_010_Struct {
  char dst1[10];
  char dst2[4];
};

int TUDBC_010_function1(int arg) {
  return ++arg;
}

void TUDBC_010_function2(int index) {
  char ch = 'a';
  TUDBC_010_Struct obj;

  if(index >= -10 && index < 0) { // [-10, -1]
    index = TUDBC_010_function1(index); // [-9, 0]
    index = TUDBC_010_function1(index); // [-8, 1]   
    
    obj.dst2[index] = ch; //@violation TYPE_UNDERRUN.BAD_COND
  }
}


