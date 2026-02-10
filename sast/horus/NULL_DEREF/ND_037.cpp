

/* ND_037 - two dereference2 from opus */
void ND_037_function() {
  char* p = 0;
  char** pp = &p;
  **pp = 'a'; //@violation NULL_DEREF
}
