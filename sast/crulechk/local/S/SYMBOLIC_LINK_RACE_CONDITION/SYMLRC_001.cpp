//@checker SYMBOLIC_LINK_RACE_CONDITION
#define S_ISLNK(X) X == 0
#define O_RDWR 0

//dummy.
struct stat {
  int st_mode;
};

extern int open(char* file, int flag);
extern int write(int fd, char* buf, int size);
extern int lstat(char* file, stat* info);

void SYMLRC_001_function(char *file){
  char *buf;
  unsigned int length;
  stat lstat_info;
  int fd;
  if (lstat(file, &lstat_info) == -1) {
    /* Handle error */
  }
  if (!S_ISLNK(lstat_info.st_mode)) {
    fd = open(file, O_RDWR); //@violation SYMBOLIC_LINK_RACE_CONDITION
    if (fd == -1) {
      /* Handle error */
    }
  }
  if (write(fd, buf, length) < length) { 
    /* Handle error */
  }
}
