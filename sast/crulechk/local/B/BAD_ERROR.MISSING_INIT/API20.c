//@checker BAD_ERROR.MISSING_INIT
#define RC_NRM 0
#define RC_ERR -1
int foo() {
  int ret = 0;
  //...
  if(ret != RC_NRM) {
    return RC_ERR; //@violation BAD_ERROR.MISSING_INIT
  }
  else if (ret == RC_NRM)
  {
  	pfmInitError();
  	return RC_ERR; 
  }
  
  //...
}