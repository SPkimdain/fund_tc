
/* RL_019 - complex source/sink. */
extern int RL_019_functionx();

extern int* RL_019_function_init();

int* RL_019_function1(int* value, int flag, int flag2) {
  switch(flag) {
  case 0:
  case 1:
    return 0;
  case 2:
    if(flag2 > 10) {
      int ret = *value + 10;
    }
    return value;
  }
  return 0;
}

int* RL_019_function2(int* intPtr, int flag, int x) {
  for(int i = 0; i < 10; i++) {
    if(x < 10) {
      x++;
    }
    if(x == 100) {
      return 0 ;
    }
  }

  return RL_019_function1(intPtr, flag, 20);
}

int* RL_019_function3(int* x, char kind, bool needToNewAlloc) {

  if(needToNewAlloc == true) {
    int type = 0;
    switch(kind) {
    case 'A':
      type = 10;
      break;
    case 'B':
      type = 20;
      break;
    case 'C':
      type = 30;
    case 'D':
      type = 5;
    }

    if(type >= 5) {
      type++;
    }
    else {
      type--;
    }

    if(type >= 10) {
      int* value = RL_019_function_init();
      return value;
    }
    else {
      return x;
    }
  }
  else {
    return 0;
  }
}

int* RL_019_function4(char kind) {
  int arr[] = { 0, 5, 10, 20 };
  int someFlag = RL_019_functionx();
  if(someFlag > 10) {
    kind++;
  }
  else {
    kind--;
  }

  int localValue = 10;
  int* intObj = 0;

  if(someFlag > 10) {
    intObj = RL_019_function3(arr + 1, kind, true);
  }
  else {
    return 0;
  }

  int* intPtr2 = RL_019_function2(intObj, 2, 5);

  if(intObj != 0) {
    return intPtr2; //@violation RETURN_LOCAL
  }
  else {
    return 0; //It's ok.
  }
}


