#include <stdio.h>
#include <unistd.h>




int setId_bad () {
	setuid(11946);
	setgid(10792); //@violation
	//must call setgid first, then setuid.
	
	FILE *f = fopen("userB_file", "w");
	fclose(f);

	return 0;
}


int setId () {
	setgid(10792);
	setuid(11946);
	

	FILE *f = fopen("userB_file", "w");
	fclose(f);

	return 0;
}


void func() {
	if(setuid(getuid()) == -1){
	   /* error handling */
	}
	if(setgid(getgid()) == -1){ // @violation BAD_PRIVILEGE_RELINQUISHMENT
	   /* error handling */
	}
}
