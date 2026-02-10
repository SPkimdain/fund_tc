
/* UDSBC_013 - Field access */
struct UDSBC_013_Struct {
  int value;
  int value2;
};

void UDSBC_013_function(int index) {
  UDSBC_013_Struct obj[5];
  
  if(index < 5 && index >= -1) {
    obj[index].value = 20; //@violation UNDERRUN.STATIC.BAD_COND
  }
}
