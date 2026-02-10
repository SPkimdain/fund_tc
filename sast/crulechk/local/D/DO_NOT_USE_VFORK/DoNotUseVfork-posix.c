// @checker DO_NOT_USE_VFORK

typedef int pid_t;

extern int vfork();
extern int execve(char *, int, int);
extern void _exit(int);

void foo()
{

	char *filename = "asdf";
	 
	pid_t pid = vfork();		//@violation DO_NOT_USE_VFORK
	 if (pid == 0 )  /* child */ {
	   if (execve(filename, 0, 0) == -1) {	//@b-violation DO_NOT_USE_VFORK
		 /* Handle error */
	   }
	   _exit(1);  /* in case execve() fails */
	}
}