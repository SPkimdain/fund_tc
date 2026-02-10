// @checker FIRST_COLUMN.LOCAL

#define DECLARE {\
  int a;         \
}

void foo () {
    int a;
    int b;
      int c;  // @violation FIRST_COLUMN.LOCAL
       static int d;  // @violation FIRST_COLUMN.LOCAL
DECLARE
}
