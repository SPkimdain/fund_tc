
/* CAV_025 - condition in while */
long CAV_025_function1(char* buf, long x) {
  buf[x] = 100;
  return x + 10;
}

void CAV_025_function2(int flag, unsigned right){
  char buf[1024 + 1];
  int filled;
  
  filled = 0;
  while(1) {
    if(filled < 512) {
      filled += CAV_025_function1(buf, sizeof buf - 1 - filled);
    }
    if(!filled) {
      break;
    }
  }
}  
  
void CAV_025_function3(int flag) {
  int a;
  unsigned int b;
  a = -20;
  if(flag > 1) {
    b = a - 20;  //@violation CAST_ALTERS_VALUE.EXT
  }  
}

