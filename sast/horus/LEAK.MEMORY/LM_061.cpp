
/* LM_061 - Check an unrealated message. */

int LM_061_gval;
int LM_061_gval2;
int LM_061_gval3;

struct LM_061_Struct {
  int* x;
};

void LM_061_function(int* regexp, LM_061_Struct* check) {
  if(regexp != 0) {
    *regexp = 10;

    LM_061_gval = 10;

    LM_061_gval2 = 20;

    LM_061_gval3 = 30;

    check->x = regexp;
  }
}

int LM_061_function2(int* regexp, LM_061_Struct* ch, int flag) {
  int ret = 0;
  if(flag > 0) {  
    LM_061_function(regexp, ch);
    ret += 10;
    return ret;
  }
  else {    
    return ret;
  }
}

void LM_061_function3(int flag) {
  int* regexp = new int[10];
  LM_061_Struct check;

  if(flag > 10) {
    LM_061_function2(regexp, &check, 10);
    
    flag++;
    
  } 
  else {
    delete[] regexp;
  }
} //@violation LEAK.MEMORY

