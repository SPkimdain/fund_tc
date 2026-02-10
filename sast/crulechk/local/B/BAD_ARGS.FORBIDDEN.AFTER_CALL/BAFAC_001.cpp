//@checker BAD_ARGS.FORBIDDEN.AFTER_CALL
#define API07_TARGET_NAME "Running message"
extern void API07_FUNC();
extern void output(const char *);

void BAFAC_run_termnate() 
{ 
    API07_FUNC();
    output(API07_TARGET_NAME); //@violation BAD_ARGS.FORBIDDEN.AFTER_CALL
} 
