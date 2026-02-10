
/* OV_001 - Very simple overrun. */
void OV_001_function() {
  int p[10] = { 0, };
  p[20] = 100; //@violation OVERRUN.STATIC
}
