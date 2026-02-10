//@checker UNUSED_VALUE

int unusedValueTest2(int flag) {
  switch(flag) {
  case 0:
    return 1;
  case 1:
    return 5;
  case 2:
  default:
    return 10;
  }
}

int unusedValueTest(int flag) {
  int res = unusedValueTest2(flag); //@violation UNUSED_VALUE

  int res2 = unusedValueTest2(flag + 5); 

  if(res2 == 10) {
    return 0;
  }
  else {
    return 1;
  }
}

int main (int argc, char *argv [])  {
	int a = 0;
	int res3 = unusedValueTest2(a); //@violation UNUSED_VALUE
	
	return 0;
}