

/* OV_002 - boundary */
void OV_002_function() {
  int value[10] = { 0, };  
  value[9] = 20; /* It's ok. */
  value[10] = 21; //@violation OVERRUN.STATIC
}
