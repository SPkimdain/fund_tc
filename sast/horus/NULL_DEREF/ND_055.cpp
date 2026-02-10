
/* ND_055 assign operator */
void ND_055_function() {
  int* ptr = 0;
  int value = 1;
  value += 10;
  value += 20;
  value += 10;

  *ptr = 10; //@violation NULL_DEREF
}

