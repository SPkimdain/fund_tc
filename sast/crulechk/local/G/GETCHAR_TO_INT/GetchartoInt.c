//@checker GETCHAR_TO_INT
#define UCHAR_MAX 255
#define UINT_MAX 4294967295

extern int getchar ( void );

void GETCHTINT_001_function (void) {
  char c;  

  do {
    c = getchar (); //@violation GETCHAR_TO_INT
  } while (c != 0);
}
