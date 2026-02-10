//@checker DO_NOT_USE_GETLOGIN_IN_MULTI_THREAD
struct passwd {
  int pw_gid;
};

extern char* getlogin();
extern passwd *getpwnam(const char *name);

extern int isTrustedGroup(int);

int DNUGIMT_001_function(){
  struct passwd *pwd = getpwnam(getlogin()); //@violation DO_NOT_USE_GETLOGIN_IN_MULTI_THREAD
  if(isTrustedGroup(pwd->pw_gid))
    return 1;
  else
    return 0;
}

