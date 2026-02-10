
/* TUDS_049 - trygraphs */
struct TUDS_049_Struct {
  int i;
  char c;
  long l;
  int p[10];
};

void TUDS_049_function(int flag) {
  TUDS_049_Struct sb;
  int value = 10;
  int index = (flag == 10) ? 5 : -5;
  
  sb.p[index] = 100; //@violation TYPE_UNDERRUN.STATIC
}

