
/* PPTL_014 - complex source/sink. */
extern int PPTL_014_functionx();

extern int* PPTL_014_function_init();

int* PPTL_014_function1(int* value, int flag, int flag2) {
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

int* PPTL_014_function2(int* intPtr, int flag, int x) {
  for(int i = 0; i < 10; i++) {
    if(x < 10) {
      x++;
    }
    if(x == 100) {
      return 0;
    }
  }

  return PPTL_014_function1(intPtr, flag, 20);
}

int* PPTL_014_function3(int* x, char kind, bool needToNewAlloc) {

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
      int* value = PPTL_014_function_init();
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

void PPTL_014_function4(char kind, int** out) {
  int arr[] = { 0, 5, 10, 20 };
  int someFlag = PPTL_014_functionx();
  if(someFlag > 10) {
    kind++;
  }
  else {
    kind--;
  }

  int localValue = 10;
  int* intObj = 0;

  if(someFlag > 10) {
    intObj = PPTL_014_function3(arr + 1, kind, true);
  }
  else {
    return;
  }

  int* intPtr2 = PPTL_014_function2(intObj, 2, 5);

  if(intObj != 0) {
    *out = intPtr2; //@violation PARAMETER_POINTER_TO_LOCAL
  }
  else {
    return;
  }
}


