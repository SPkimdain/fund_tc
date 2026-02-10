//@checker BAD_ERROR.MISSING_RETURN
extern void SET_ERR_API21(const char *);
int Fun_BERRMSRET_001_function(const char * x, int flag) {
  if(flag > 10) {
    return 0;
  }
  
  SET_ERR_API21("ERR0012"); 
} //@violation BAD_ERROR.MISSING_RETURN

