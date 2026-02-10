//@checker RETURN_ERRNO_WITH_ERRNO_T_TYPE
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
typedef int fpos_t;
extern int fgetpos ( FILE * stream, fpos_t * pos );

int RETERRNOWETT_001_function(FILE* file) //@violation RETURN_ERRNO_WITH_ERRNO_T_TYPE
{
	fpos_t offset;
	int errno = 0;
	if(fgetpos(file, &offset) != 0 )
	{
		return errno; //@b-violation RETURN_ERRNO_WITH_ERRNO_T_TYPE
	}
	else
	{
		return 0;
	}	

	errno = 0;
	if(fgetpos(file, &offset) != 0 )
	{
		return errno; //@b-violation RETURN_ERRNO_WITH_ERRNO_T_TYPE
	}
	else
	{
		return 0;
	}	
}
