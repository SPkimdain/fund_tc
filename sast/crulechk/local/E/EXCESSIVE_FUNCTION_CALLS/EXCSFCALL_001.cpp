//@checker EXCESSIVE_FUNCTION_CALLS
extern void EXCSFCALL_001_function1();
extern void EXCSFCALL_001_function2();
extern void EXCSFCALL_001_function3();
extern void EXCSFCALL_001_function4();
extern void EXCSFCALL_001_function5();
extern void EXCSFCALL_001_function6();
extern void EXCSFCALL_001_function7();
extern void EXCSFCALL_001_function8();

void EXCSFCALL_001_box() { //@violation EXCESSIVE_FUNCTION_CALLS
  EXCSFCALL_001_function1();
  EXCSFCALL_001_function2();
  EXCSFCALL_001_function3();
  EXCSFCALL_001_function4();
  EXCSFCALL_001_function5();
  EXCSFCALL_001_function6();
  EXCSFCALL_001_function7();
  EXCSFCALL_001_function8();
}

