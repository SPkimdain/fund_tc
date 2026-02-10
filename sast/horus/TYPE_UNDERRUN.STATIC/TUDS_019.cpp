
/* TUDS_019 - short circuit2 */
struct TUDS_019_Struct {
  int i;
  char c;
  long l;
  int p[5];
};


void TUDS_019_function() {
  TUDS_019_Struct sb;
  sb.p[0] = 0;
  int* ptr = sb.p;
  int x = 10;
  int compareValue = 20;
  int ret = 0;
  
  ret = *ptr; //It's ok.

  ptr = sb.p;

  if(compareValue > *(ptr - 10)) { // @violation TYPE_UNDERRUN.STATIC
    x++;
  }
}
