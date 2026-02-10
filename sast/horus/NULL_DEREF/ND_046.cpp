
/* ND_046 - new */
void ND_046_function() {
  int *p = new int(0); //*p = 0
  *p = 10; //It's ok.
  delete p;
  p = 0;
  *p = 10; //@violation NULL_DEREF
}

