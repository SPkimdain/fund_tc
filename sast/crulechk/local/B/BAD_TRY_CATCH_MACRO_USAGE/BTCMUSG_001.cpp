//@checker BAD_TRY_CATCH_MACRO_USAGE
#define PFM_TRY(x) do {} while(0)
#define PFM_CATCH dummy

int BTCMUSG_001_try() {
  return 1;
}

int BTCMUSG_001_try2() {
  return 10;
}


void BTCMUSG_001_function3() {
  PFM_TRY(BTCMUSG_001_try());
  PFM_CATCH :
  /* some codes here */
  PFM_TRY(BTCMUSG_001_try2()); //@violation BAD_TRY_CATCH_MACRO_USAGE
}
