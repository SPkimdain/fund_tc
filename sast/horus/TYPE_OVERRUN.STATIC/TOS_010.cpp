

/* TOS_010 - buffer_overrun_02_03 from opus */
struct TOS_010_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

void TOS_010_function1() {
  int i;
  TOS_010_Struct sb;

  for(i = 0; i < 256; i++) {
    sb.buf[i] = 'a';
  }

  sb.buf[i] = 0; //@violation TYPE_OVERRUN.STATIC
}
