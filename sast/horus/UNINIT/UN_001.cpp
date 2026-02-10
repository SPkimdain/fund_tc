#pragma warning(disable : 4700)

/* UN_001 - simple uninit */
void UN_001_function() {
  int a;
  int b;
  b = a; //@violation UNINIT

  int c = a; //Ignore.

  int d = a; //Ignore.
}
