
/* TOS_017 - unary operator order */
struct TOS_017_Struct {
  int i;
  char c;
  long l;
  int* arr[2];
};

void TOS_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  TOS_017_Struct sb;

  sb.arr[0] = &p;
  sb.arr[1] = 0;

  int index = 1;

  // index + 1 after assign arr[1].
  ptr = sb.arr[index++]; //It's ok.

  index = 1;
  // access arr[2] after index + 1.
  ptr = sb.arr[++index]; //@violation TYPE_OVERRUN.STATIC
}
