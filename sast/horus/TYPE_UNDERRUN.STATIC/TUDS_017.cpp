
/* TUDS_017 - unary operator order */
struct TUDS_017_Struct {
  int i;
  char c;
  long l;
  int* arr[2];
};

void TUDS_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  TUDS_017_Struct sb;

  sb.arr[0] = &p;
  sb.arr[1] = 0;

  int index = 0;

  ptr = sb.arr[index--]; //It's ok.

  index = 0;
  ptr = sb.arr[--index]; //@violation TYPE_UNDERRUN.STATIC
}
