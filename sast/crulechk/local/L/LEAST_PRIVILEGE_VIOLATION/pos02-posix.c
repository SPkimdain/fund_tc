//@checker LEAST_PRIVILEGE_VIOLATION
#define NULL 0

typedef struct _iobuf
{
 char* _ptr;  
 int _cnt;    
 char* _base; 
 int _flag; 
 int _file; 
 int _charbuf; 
 int _bufsiz;  
 char* _tmpfname; 
} FILE;

extern FILE * fopen ( const char * filename, const char * mode );
extern char * fgets ( char * str, int num, FILE * stream );
extern int fclose ( FILE * stream );


void chroot(const char* path)
{
	/* Dummy for test */
	return;
}

void chdir(const char* path)
{
	/* Dummy for test */
	return;
}
void seteuid(int auth)
{
	/* Dummy for test */
	return;
}

char buf[100];

char* privilegeDown(){
	FILE* fp; 
	chroot("/var/tmp"); //@violation LEAST_PRIVILEGE_VIOLATION
	chdir("/");
	fp = fopen("filename", "r");
	if(fp != NULL)
	{
		fgets(buf, sizeof(buf), fp);
		fclose(fp);
		return buf;
	}
	else
	{
		return NULL;
	}
}

char* privilegeDown2(){
	FILE* fp; 
	chroot("/var/tmp");
	chdir("/");
	fp = fopen("filename", "r");
	/* seteuid를 사용하므로 문제 없음. */
	seteuid(1);
	if(fp != NULL)
	{
		fgets(buf, sizeof(buf), fp);
		fclose(fp);
		return buf;
	}
	else
	{
		return NULL;
	}
}




int main()
{
	privilegeDown();

	return 0;
}
