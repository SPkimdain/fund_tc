
/* TOS_013 - for2 */
struct TOS_013_Struct {
  int i;
  char c;
  long l;
  int buf[3];
};

void TOS_013_function(int value, int value2) {
  int p = 100;
  TOS_013_Struct sb;
  int ret = 0;

  for(int i = 0; i < 2; i++) {

    if(value > 10) { // True or False
      if(value2 > 5) { // True or False
        ret += sb.buf[4]; //@violation TYPE_OVERRUN.STATIC
      }
    }
  }
}
