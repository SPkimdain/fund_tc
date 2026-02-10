
/* UDDBC_013 - Field access */
struct UDDBC_013_Struct {
  int value;
  int value2;
};

void UDDBC_013_function(int index) {
  UDDBC_013_Struct* obj = new UDDBC_013_Struct[5];
  if(obj == 0) {
    return;
  }
  
  if(index < 5 && index >= -1) {
    obj[index].value = 20; //@violation UNDERRUN.DYNAMIC.BAD_COND
  }

  delete[] obj;
}
