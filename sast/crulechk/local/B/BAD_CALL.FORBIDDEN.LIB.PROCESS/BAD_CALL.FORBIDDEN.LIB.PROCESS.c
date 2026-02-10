// @checker BAD_CALL.FORBIDDEN.LIB.PROCESS

extern void exit(int code);

typedef int pid_t;

extern pid_t fork_FB08();

void BCFBDNLP_001_function(){
    int   counter  = 0;
    pid_t pid;
    pid = fork_FB08();  // @violation BAD_CALL.FORBIDDEN.LIB.PROCESS
    exit(1);
}
