#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_PATH 1024
static char *suffix = ".ext";

char* addsfx_bad(char *buf)
{
	return strcat(buf, suffix); // @violation
}


unsigned int addsfx(char *buf, int size)
{
    unsigned int ret = strlcat(buf, suffix, size);
    if (ret >= size)
    {
        fprintf(STDERR_FILENO, "Buffer too small....\n");
    }
    return ret;
}



void unCalcedBufferSize()
{
	char file[MAX_PATH];
	//...
	addsfx_bad(file);
	//...
}

void calcedBufferSize()
{
	char file[MAX_PATH];
	addsfx(file, sizeof(file));
}

