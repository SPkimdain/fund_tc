
/* ODBC_013 - Field access */
struct ODBC_013_Struct {
  int value;
  int value2;
};

void ODBC_013_function(unsigned index) {
  ODBC_013_Struct* obj = new ODBC_013_Struct[5];
  if(obj == 0) {
    return;
  }
  
  if(index < 10) {
    obj[index].value = 20; //@violation OVERRUN.DYNAMIC.BAD_COND
  }

  delete[] obj;
}
