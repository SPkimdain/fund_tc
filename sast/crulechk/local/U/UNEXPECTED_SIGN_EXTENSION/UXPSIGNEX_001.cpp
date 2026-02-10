//@checker UNEXPECTED_SIGN_EXTENSION

extern int info[256];
int UXPSIGNEX_001_function(int id) {
  short s;
  unsigned sz;
  s = id; //@violation UNEXPECTED_SIGN_EXTENSION
  if (s > 256) return 0;
  sz = s;
  return info[sz];
}
