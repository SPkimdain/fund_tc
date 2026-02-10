// @checker ENSURE_PRIVILEGE_RELINQUISHMENT

extern int seteuid(unsigned int euid);
extern int setuid(unsigned int uid);
extern unsigned int getuid(void);

void ENSPRIVR_001_function(int need_more_privileges){
	/* Temporarily drop privileges */
	if (seteuid(getuid()) != 0) {
	  /* Handle error */
	}
	 
	/* Code intended to run with lower privileges */
	 
	if (need_more_privileges) {
	  /* Restore privileges */
	  if (seteuid(0) != 0) {
		/* Handle error */
	  }
	 
	  /* Code intended to run with elevated privileges */
	}
	 
	/* ... */
	 
	/* Permanently drop privileges */
	if (setuid(getuid()) != 0) { //@violation ENSURE_PRIVILEGE_RELINQUISHMENT
	  /* Handle error */
	}
}