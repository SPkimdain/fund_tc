// @checker FIRST_COLUMN.GLOBAL

#define DECL(a) \
  int a

int a;
int b;
  int c;  // @violation FIRST_COLUMN.GLOBAL
    int d;  // @violation FIRST_COLUMN.GLOBAL



DECL(e);
