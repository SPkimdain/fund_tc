//@checker BAD_PRIVILEGE_RELINQUISHMENT

extern int setuid(int id);
extern int getuid();
extern int setgid(int id);
extern int getgid();

void BPRIVRQSMNT_001_function() {

  if(setuid(getuid()) == -1){ 
    /* error handling */
  }
  if(setgid(getgid()) == -1){ //@violation BAD_PRIVILEGE_RELINQUISHMENT
    /* error handling */
  }
  
  return ;
}

void BPRIVRQSMNT_001_function2() {
  
  if(setgid(getgid()) == -1){ //It's ok.
    /* error handling */
  }
  
  if(setuid(getuid()) == -1){  
    /* error handling */
  }
  
  return ;
}
