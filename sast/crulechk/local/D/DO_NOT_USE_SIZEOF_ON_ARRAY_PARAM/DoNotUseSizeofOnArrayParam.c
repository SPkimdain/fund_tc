// @checker DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM


extern int memset(void* s, int c, unsigned t);


void DNUSOAP_001_function1(int array[]) {
  int i = 0;
  for (i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {	//@violation	DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
     array[i] = 0;
   }
}
 
void DNUSOAP_001_function2(void) {
  int dis[12];
 
  DNUSOAP_001_function1(dis);
  /* ... */
}

 
void DNUSOAP_001_function3(int a[100]) {
  memset(a, 0, sizeof(a)); //@violation	DO_NOT_USE_SIZEOF_ON_ARRAY_PARAM
}
 
int DNUSOAP_001_function4(void) {
  int b[100];
  DNUSOAP_001_function3(b);
 // assert(b[100 / 2]==0); /* may fail */
  return 0;
}
