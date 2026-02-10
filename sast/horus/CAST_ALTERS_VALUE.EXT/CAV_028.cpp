
/* CAV_028 - small type, min compare */
extern unsigned int CAV_028_function1();
extern unsigned int CAV_028_function2();
extern unsigned int CAV_028_function3();

void CAV_028_function4(int flag, int level){
  level = CAV_028_function1() * CAV_028_function2() + CAV_028_function3() >> 14U;
  
  int a;
  unsigned int b;
  a = -20;
  if(flag > 1) {
    b = a - 20;  //@violation CAST_ALTERS_VALUE.EXT
  }
  else {
    b = a + 40; //It's ok. a = 20;
  }
}
