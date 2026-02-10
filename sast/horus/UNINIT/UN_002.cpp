#pragma warning(disable : 4700)

/* UN_002 - uninit pointer*/
void UN_002_function() {
  int* a;
  int* b;
  b = a; //@violation UNINIT
}
