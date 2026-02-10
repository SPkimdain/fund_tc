
/* ND_012 - for */
void ND_012_function() {
  int value = 0;
  int* arg = 0;
  for(int i = 0; i < 10; i++) {
    value++;
  }

  
  *arg = 10; //@violation NULL_DEREF
  
}

