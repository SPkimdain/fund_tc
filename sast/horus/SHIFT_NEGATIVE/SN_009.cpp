
/* SN_009 - complex value */

int SN_009_function1(int data) {
  int y = 2;
  data = data - y;

  return data;
}

int SN_009_function2(int data) {
  if(data == 0) {
    return 1;
  }
  else {
    return data;
  }  
}

void SN_009_function3(int flag, int check1, int check2) {
  unsigned int p = 10;
  int x = 0;
  x = x + 2;
  
  for(int iter = 0; iter < flag; iter++) {
    x -= 5;
    break;
  }

  x = SN_009_function2(x);

  x = SN_009_function2(x);


  if(check1 == 10 && check2 == 5) {
    x = x + 10;
    p = p << x; 
  }
  else if(check1 == 5 && check2 == 3) {
    x = x + 1;
    p = p << x; //@violation SHIFT_NEGATIVE  
  }
  else {
    p = p << 3; 
  }

}

