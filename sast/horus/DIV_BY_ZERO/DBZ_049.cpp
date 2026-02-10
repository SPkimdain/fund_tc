
/* DBZ_049 - trygraphs */
void DBZ_049_function(int flag) {
  int value = 20;
  int select = 
    (flag == 10) ? 
    value : 
    0;
  
  int ret = 1000 / select; //@violation DIV_BY_ZERO

}

