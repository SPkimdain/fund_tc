// @checker COMPLEX_FUNC_DECL

typedef void SighandlerType(int signum);
extern SighandlerType *signal1(
  int signum,
  SighandlerType *handler
);

void (*signal(int, void (*)(int)))(int);	//@violation COMPLEX_FUNC_DECL
