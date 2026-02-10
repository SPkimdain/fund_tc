#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



void unchecked()
{
	int fd;
	setgid(11946); //@violation
  	setuid(10792); //@violation
	fd  = open ("fchown_unc.txt", O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR)	;
	
	fchown (fd,1000,0); //@violation

	fopen([fullFilePath UTF8String], "rb"); //@violation

	close(fd);
}



void checked()
{
	int fd;
	if(!setgid(11946))
	{
		return;
	}
	if (setuid(10792) != 0)
	{
		return;
	}
  	
	fd  = open ("fchown_chk.txt", O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR)	;
	if ( -1 == fchown (fd,1000,0))
	{
		if(fprintf(stderr, "failed to changing file owner") < 1)
		{
		    return;
		}
	}
	close(fd);	
}
