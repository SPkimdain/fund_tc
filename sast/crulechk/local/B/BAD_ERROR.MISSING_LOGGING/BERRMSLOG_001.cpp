//@checker BAD_ERROR.MISSING_LOGGING
enum RET_LOG {
  RC_ERR = -1
};

extern void SET_ERR(int);

int BERRMSLOG_001_function() {
  return RC_ERR; //@violation BAD_ERROR.MISSING_LOGGING
} 

