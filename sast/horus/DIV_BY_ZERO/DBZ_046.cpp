
/* DBZ_046 - & operator */
void DBZ_046_function() {
  int logical1 = 0x01; // 1
  int logical2 = 0x05; // 5
  int logical3 = logical1 & logical2; // 1
  
  int ret = 1000 / (logical3 - 1); //@violation DIV_BY_ZERO
}


