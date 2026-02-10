
/* UN_059 - complex array */

int UN_059_function1(int** ap) {
  int ret = *((*ap)++);

  return 0;
}

int UN_059_function2(int* ap) {
  int ret = UN_059_function1(&ap);

  return 0;
}

void UN_059_function3(int value) {
  int buf[100];
  int* ptr = 0;

  for(int i = 0; i < 100; i++) {
    buf[i] = value;
  }

  ptr = buf;

  UN_059_function2(ptr); //It's ok.

  int a;
  int b;
  b = a; //@violation UNINIT

}
