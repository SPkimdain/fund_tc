
/* ND_058 - complex source/sink. */
extern int ND_058_functionx();

int ND_058_function1(int* value, int flag, int flag2) {  
  switch(flag) {
  case 0:
  case 1:
    return 0;
  case 2:
    if(flag2 > 10) {
      int ret = *value + 10;
    }
    else {
      return 2;
    }
  }
  return 1;
}

void ND_058_function2(int* intPtr, int flag, int x) {
  for(int i = 0; i < 10; i++) {
    if(x < 10) {
      x++;
    }
    if(x == 100) {
      return;
    }
  }

  int ret = ND_058_function1(intPtr, flag, 20);
}

int* ND_058_function3(int* x, char kind, bool needToNewAlloc) {

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
      int* value = new int(type);
      return value;
    }
    else {
      return 0;
    }
  }
  else {
    return x;
  }
}

bool ND_058_function4(char kind) {
  int someFlag = ND_058_functionx();
  if(someFlag > 10) {
    kind++;
  }
  else {
    kind--;
  }
  
  int localValue = 10;
  int* intObj = 0;
  
  if(someFlag > 10) {
    intObj = ND_058_function3(&localValue, kind, true);
  }
  else {
    return false;
  }
  
  ND_058_function2(intObj, 2, 5); //@violation NULL_DEREF

  if(intObj != 0) {
    delete intObj;
    return true;
  }
  else {
    return false;
  }
}


