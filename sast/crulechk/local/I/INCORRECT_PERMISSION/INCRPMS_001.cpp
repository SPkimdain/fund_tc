//@checker INCORRECT_PERMISSION
extern int umask(int cmask);

void INCRPMS_001_function() { 
  umask(0);    //@violation INCORRECT_PERMISSION  
}
