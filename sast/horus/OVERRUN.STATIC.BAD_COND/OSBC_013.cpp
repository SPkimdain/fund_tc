
/* OSBC_013 - Field access */
struct OSBC_013_Struct {
  int value;
  int value2;
};

void OSBC_013_function(unsigned index) {
  OSBC_013_Struct obj[5];
  
  if(index < 10) {
    obj[index].value = 20; //@violation OVERRUN.STATIC.BAD_COND
  }
}
