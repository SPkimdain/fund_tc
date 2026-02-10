
/* TOBC_001 - buffer_overrun_02_06 from opus */
struct TOBC_001_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TOBC_001_function(int i) {
  TOBC_001_Struct sb;

  if(i > 256)
    return -1;
  else //[min, 256]
    sb.buf[i] = 'a';  //@violation TYPE_OVERRUN.BAD_COND

  return 0;
}

