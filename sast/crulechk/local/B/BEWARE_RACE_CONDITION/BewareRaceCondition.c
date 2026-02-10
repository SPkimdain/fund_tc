// @checker BEWARE_RACE_CONDITION

extern int open (const char* filename,  int);
extern void read(int fildes, void *buf, int nbyte);
extern int printf ( const char * format, ... );
extern int fork();

void foo(const char* filename) {
	char c;
	int pid;
	 
	int fd = open(filename, 1);	//@violation BEWARE_RACE_CONDITION
	if (fd == -1) {
	  /* Handle error */
	}
	read(fd, &c, 1);
	printf("root process:%c\n",c);
	 
	pid = fork();
	if (pid == -1) {
	  /* Handle error */
	}
	 
	if (pid == 0) { /*child*/
	  read(fd, &c, 1);
	  printf("child:%c\n",c);
	}
	else { /*parent*/
	  read(fd, &c, 1);
	  printf("parent:%c\n",c);
	}
}
