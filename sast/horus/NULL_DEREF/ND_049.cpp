
/* ND_049 - trygraphs */
void ND_049_function(int flag) {
  int value = 10;
  int* ptr = 
    (flag == 10) ? 
    &value : 
    0;
  
  *ptr = 100; //@violation NULL_DEREF

}

