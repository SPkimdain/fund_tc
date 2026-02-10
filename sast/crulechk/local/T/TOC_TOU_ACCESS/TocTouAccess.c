//@checker TOC_TOU_ACCESS

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h>

#ifdef _WIN32

#include <io.h>

# define STAT _stat
# define OPEN _open
# define WRITE _write
# define O_CREAT _O_CREAT
# define O_EXCL _O_EXCL
# define O_RDWR _O_RDWR
# define S_IREAD _S_IREAD
# define S_IWRITE _S_IWRITE
# define CLOSE _close
# define FSTAT _fstat

#else
# define STAT stat
# define OPEN open
# define WRITE write
# define CLOSE close
# define FSTAT fstat
#endif

void TOCTOUACC_001_function1()
{
    {
        char filename[100] = "";
        struct STAT statbuf;
        int fd = -1;
        fgets(filename, 100, stdin);
        filename[strlen(filename)-1] = '\0'; /* remove newline */
        if (STAT(filename, &statbuf) == -1) exit(1);
        fd  = OPEN(filename, O_CREAT | O_RDWR, S_IREAD|S_IWRITE);//@violation TOC_TOU_ACCESS
        /* FLAW: Open and write to the file without a call to fstat() */
        if (fd == -1) exit(1);
		if (WRITE(fd, "Bad Sink...", 25) == -1)	
		{
			exit(1);
		}
        if (fd != -1) CLOSE(fd);
    }
}

void TOCTOUACC_001_function2()
{
	int fd = -1;
	if (WRITE(fd, "Bad Sink...", 25) == -1)
		{
			exit(1);
		}
}