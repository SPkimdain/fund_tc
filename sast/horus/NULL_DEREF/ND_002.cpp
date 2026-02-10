

/* ND_002 - assign a pointer. */
void ND_002_function() {
  int value = 5;
  int* ptr1 = &value;
  *ptr1 = 10; /* It's ok. */
  ptr1 = 0;
  int* ptr2 = ptr1;
  *ptr2 = 10; //@violation NULL_DEREF
}
