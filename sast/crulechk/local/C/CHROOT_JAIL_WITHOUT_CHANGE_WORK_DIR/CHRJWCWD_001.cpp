//@checker CHROOT_JAIL_WITHOUT_CHANGE_WORK_DIR
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

extern void chroot(const char* path);
extern char * fgets ( char * str, int num, FILE * stream );

void CHRJWCWD_001_function(FILE *network){
  FILE *localfile;
  char filename[80], buf[80];
  int len;
  chroot("/var/ftproot"); //@violation CHROOT_JAIL_WITHOUT_CHANGE_WORK_DIR
  fgets(filename, sizeof(filename), network);
}
