
/* OV_044 - buffer_overrun_03_03 from opus */
struct OV_044_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

void OV_044_function() {
  int i;
  OV_044_Struct sb;
  char buf[256];
  sb.buf = buf;

  for(i = 0; i < 256; i++)
    sb.buf[i] = 'a';

  i++;
  sb.buf[i] = 0;  //@violation OVERRUN.STATIC
}
