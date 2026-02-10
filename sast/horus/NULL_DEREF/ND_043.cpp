

/* ND_043 - three null dereference3 from opus */
void ND_043_function() {
  char* p = 0;
  char** pp = &p;
  char*** ppp = &pp;
  ***ppp = 'a';       //@violation NULL_DEREF
}
