//@checker BAD_CALL.REQUIRED.ARGS
#define LBCALLWA_NUM 0

extern void LB_call_WA(int);

void BCREQA_001_function() {
  LB_call_WA(0); //@violation BAD_CALL.REQUIRED.ARGS
}
