
/* ND_036 - two dereference1 from opus */
void ND_036_function() {
  char** pp = 0;
  **pp = 'a'; //@violation NULL_DEREF
}
