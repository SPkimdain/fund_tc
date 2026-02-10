
/* ND_001 - Very simple null dereference. */
void ND_001_function() {
  int* p = 0;
  *p = 100; //@violation NULL_DEREF
}
