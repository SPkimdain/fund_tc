
/* ND_042 - three null dereference2 from opus */
void ND_042_function() {
  char** pp = 0;
  char*** ppp = &pp;
  ***ppp = 'a';       //@violation NULL_DEREF
}

