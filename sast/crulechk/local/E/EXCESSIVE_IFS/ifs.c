//@checker EXCESSIVE_IFS

void many_ifs(int arg) {
  int a;
  if (arg == 0) {
    a = 0;
  }
  if (arg == 1) {
    a = 1;
  }
  if (arg == 2) { //@violation EXCESSIVE_IFS
    a = 2;
  }
  if (arg == 3) { // EXCESSIVE_IFS
    a = 3;
  }
  if (arg == 4) { // EXCESSIVE_IFS
    a = 4;
  }
}