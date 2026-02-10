//@checker DO_NOT_USE_ERRNO

extern unsigned long strtoul(const char* str, char** endptr, int base);
extern int errno;

void DNUERRNO_001_function(const char* str) {
    unsigned long number;
    char* endptr = 0;
    errno = 0; //@violation DO_NOT_USE_ERRNO
    number = strtoul(str, &endptr, 0);
    
    return;
}
