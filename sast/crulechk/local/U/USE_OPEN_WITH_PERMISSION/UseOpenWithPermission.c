// @checker USE_OPEN_WITH_PERMISSION

#define O_CREAT                00000100 
#define O_WRONLY        00000001

extern int open(char *, int, ...);

int foo(void) {

	char *file_name;
	int fd;
	int file_access_permissions;
	 
	/* initialize file_name */
	 
	fd = open(file_name, O_CREAT | O_WRONLY);	//@violation USE_OPEN_WITH_PERMISSION
	/* access permissions were missing */

	fd = open(file_name,  O_CREAT | O_WRONLY, file_access_permissions);
	 
	if (fd == -1){
	  /* Handle error */
	}
}