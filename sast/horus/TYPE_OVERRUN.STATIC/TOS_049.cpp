
/* TOS_049 - trygraphs */
struct TOS_049_Struct {
  int i;
  char c;
  long l;
  int p[10];
};

void TOS_049_function(int flag) {
  TOS_049_Struct sb;
  int value = 10;
  int index = (flag == 10) ? 5 : 10;
  
  sb.p[index] = 100; //@violation TYPE_OVERRUN.STATIC
}

