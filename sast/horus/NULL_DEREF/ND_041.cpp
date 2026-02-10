
/* ND_041 - three null dereference1 from opus */
void ND_041_function() {
  char*** ppp = 0;
  ***ppp = 'a';   //@violation NULL_DEREF
}

