
/* TUDBC_001 - buffer_overrun_02_06 from opus */
struct TUDBC_001_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TUDBC_001_function(int i) {
  TUDBC_001_Struct sb;

  if(i > 256) {
    return -1;
  }
  else if(i >= 0) {// [-1, 256]
    sb.buf[i - 1] = 'a';  //@violation TYPE_UNDERRUN.BAD_COND
  }
  else {}

  return 0;
}

