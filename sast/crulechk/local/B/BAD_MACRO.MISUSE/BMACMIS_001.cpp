//@checker BAD_MACRO.MISUSE
extern void pthread_cleanup_push(void(*)(void*), void*);

void BMACMIS_001_function(void *a){
  int b = (*(int*)(a))++;
}
 
void BMACMIS_001_function2() {
  int var = 0;
  pthread_cleanup_push(BMACMIS_001_function,((void*)&var));  //@violation BAD_MACRO.MISUSE
}
