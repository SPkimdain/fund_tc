
/* OV_049 - trygraphs */
void OV_049_function(int flag) {
  int p[10] = { 0, };
  int value = 10;
  int index = (flag == 10) ? 5 : 10;
  
  p[index] = 100; //@violation OVERRUN.STATIC
}

