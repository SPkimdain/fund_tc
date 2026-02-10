/* typedef */

typedef unsigned char uint_8;
typedef signed char sint_8;

void CAV_016_function(int flag) {
  sint_8 sch = -5;
  uint_8 uch = 0;

  if(flag > 100) {
    uch = sch; //@violation CAST_ALTERS_VALUE.EXT
  }
}


