//@checker FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT

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

void FWVRTSHESE_001_function1()  //@violation FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT
{
	int local;
	local = 0;  
}



int FWVRTSHESE_001_function2()  //compliant
{

	return 0;
}

void FWVRTSHESE_001_function4(int &rNum) //compliant
{
  rNum++;
}


void FWVRTSHESE_001_function5(int iNum, int *pNum) //compliant
{
  *pNum++;
}


void FWVRTSHESE_001_function6(int n)   //compliant
{   
	if (n == 3)  
	  throw 4;
}


void FWVRTSHESE_001_function7()  //compliant
{
	FILE *fp = fopen("abc.txt", "wt");
}

