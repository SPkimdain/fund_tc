//@checker CALL_UNINIT_VAR_WITH_CONST

extern int call_uninit_foo(const int *p);

void call_uninit_bar_bad(void){
  int y2;
  int x2;
  call_uninit_foo(&y2); //@violation CALL_UNINIT_VAR_WITH_CONST
}