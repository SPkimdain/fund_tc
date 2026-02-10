// @checker CHECK_EXIST_LINK_FILES

#define O_RDWR 0
#define O_NOFOLLOW 1

extern int open(char* fileName, int oFlag);
extern int write(int fd, void* buf, unsigned int nbyte);

int CHECKEXLF_001_function(void) {

	char *file_name = "asdf";
	char *userbuf = "what?";
	unsigned int userlen = 5;

	int fd = open(file_name, O_RDWR | O_NOFOLLOW);
	if (fd == -1) {
	  /* handle error */
	}
	write(fd, userbuf, userlen);
	 
	int fd2 = open(file_name, O_RDWR);	//@violation CHECK_EXIST_LINK_FILES
	if (fd2 == -1) {
	   /* handle error */
	}
	write(fd2, userbuf, userlen);

	
	
	return 0;
}
