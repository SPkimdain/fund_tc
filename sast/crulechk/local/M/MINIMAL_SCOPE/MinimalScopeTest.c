//@checker MINIMAL_SCOPE

int a = 2; //@violation MINIMAL_SCOPE

static int b = 3; //@violation MINIMAL_SCOPE

static int c = 5; //It's ok.

int minimalScope1() {
  int ret = 0;
  if (a++ == 20) {
    ret++;
    return ret;
  }
  c++;
  return 1;
}

int minimalScope2() {
  c++;
  b += 20;
  
  return 0;
}
