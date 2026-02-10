//@checker BAD_MACRO_USAGE
extern void assert(int x); //dummy.

typedef void (*handler_type)(int);

void execute_handler(handler_type handler, int value) {
  handler(value);
}
void BMACUSG_001_function(int e) {
  execute_handler(&(assert), e < 0); //@violation BAD_MACRO_USAGE
}
