// @checker STRTOK_CHANGES_STRING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void STOKCHSTR_001_function(){
	char *token;
	char *path = getenv("PATH");
	 
	token = strtok(path, ":");
	puts(token);
	 
	while (token = strtok(0, ":")) {
	  puts(token);
	}
	 
	printf("PATH: %s\n", path);	//@violation	STRTOK_CHANGES_STRING
	/* PATH is now just "/usr/bin" */
}

int STOKCHSTR_001_function2() {
	char *token;
	char *path = new char[10];
	
	char *path2 = new char[20];
	
	if(path == NULL) {
	  return 0;
	}
	
	if(path == NULL) return 0;
	 
	token = strtok(path, ":");
	puts(token);
	
	 
	while (token = strtok(0, ":")) {
	  puts(token);
	}
	
	char* token2 = strtok(path2, ":");
	 
	printf("PATH: %s\n", path);	//@violation	STRTOK_CHANGES_STRING
	/* PATH is now just "/usr/bin" */
	
	if( path2 != NULL )	//@violation	STRTOK_CHANGES_STRING
	{
	}
	
	return 0;
}
