// @checker IMPROPER_USAGE.FILE_OBJECT
struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flags;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;

struct _st{
	FILE* f;
	FILE f1;
};

extern FILE* tmpfile();

void IMPUFO_001_function(void)
{
	
	
	FILE *pf1 = tmpfile( );
   FILE *pf2;
   FILE  f3;
	struct _st st;
	
 
	pf2 = pf1;         /* Compliant */
    f3 = *pf2;        /* Non-compliant */ //@violation IMPROPER_USAGE.FILE_OBJECT
    
	pf1->_flags = 0;	//@violation IMPROPER_USAGE.FILE_OBJECT
	pf2 = pf1;	// okay
	f3 = *pf2;	//@violation IMPROPER_USAGE.FILE_OBJECT
	f3._flags = 0; //@violation IMPROPER_USAGE.FILE_OBJECT
	
	
	
	st.f = pf1;
	st.f1 = *pf2; //@violation IMPROPER_USAGE.FILE_OBJECT
	st.f->_flags = 0; //@violation IMPROPER_USAGE.FILE_OBJECT
	st.f1._flags = 0;//@violation IMPROPER_USAGE.FILE_OBJECT
}



