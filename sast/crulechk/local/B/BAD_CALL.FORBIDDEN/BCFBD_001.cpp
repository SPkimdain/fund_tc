//@checker BAD_CALL.FORBIDDEN
extern void forbidden();

void BCFBD_001_function() {
  forbidden();  //@violation BAD_CALL.FORBIDDEN
}
