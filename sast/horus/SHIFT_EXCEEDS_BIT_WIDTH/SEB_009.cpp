
/* SEB_009 - complex value */

int SEB_009_function1(int data) {
  int y = 2;
  data = data + y;

  return data;
}

int SEB_009_function2(int data) {
  if(data == 0) {
    return 1;
  }
  else {
    return data;
  }
}

void SEB_009_function3(int flag, int check1, int check2) {
  unsigned int p = 10;
  int x = 0;
  x = x + 2;

  for(int iter = 0; iter < flag; iter++) {
    x += 20; // 22
    break;
  }

  x = SEB_009_function2(x);

  x = SEB_009_function2(x); // 24


  if(check1 == 10 && check2 == 5) {
    x = x + 5; // 29
    p = p << x;
  }
  else if(check1 == 5 && check2 == 3) {
    x = x + 10; // 34
    p = p << x; //@violation SHIFT_EXCEEDS_BIT_WIDTH  
  }
  else {
    p = p << 3;
  }

}

