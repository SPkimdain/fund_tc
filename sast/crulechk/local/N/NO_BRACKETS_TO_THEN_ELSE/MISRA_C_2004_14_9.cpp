//@checker NO_BRACKETS_TO_THEN_ELSE



#define OK 1
#define WARNING 2
#define WARN(msg) {if (!quiet) fprintf msg ; if (exit_code == OK) exit_code = WARNING;}

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

extern int fprintf ( FILE * stream, const char * format, ... );

int static_12(int p_1, int p_2)
{
   int i = 1;
   int j = 0;
 
   if (p_1 > 0)
   {
     i = i - 1;
   }
   else //@violation NO_BRACKETS_TO_THEN_ELSE
      i = i + 1;          /* not compliant */
 
   if (p_2 > 0)
   {
      j = j + p_2;
   }
   else if (p_2 < 0)
   {
      j = j - p_2;
   }
   else
   {
      j = i;
   }

   return j;
}

int main()
{
	FILE* stderr;
	bool quiet = false;
	int exit_code = 0;
	int x = 0;
	if( x == 1 ) //@violation NO_BRACKETS_TO_THEN_ELSE
		x++;
	else if( x > 10 ) //@violation NO_BRACKETS_TO_THEN_ELSE
		x--;
	else if( x > 50 ) //@violation NO_BRACKETS_TO_THEN_ELSE
		x += 10;
	else //@violation NO_BRACKETS_TO_THEN_ELSE
		x += 2;

	if( x ); //@violation NO_BRACKETS_TO_THEN_ELSE
	
	WARN((stderr, "abcdef" )) //@violation NO_BRACKETS_TO_THEN_ELSE

	return 1;
}
