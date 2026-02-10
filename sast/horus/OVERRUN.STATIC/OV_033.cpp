
/* OV_033 - src31_bad1 from opus */
void OV_033_function1() {
  char dest[100];
  char src[100];
  unsigned int i;
  /* ... */
  for(i = 0; i< 100; i++){
    src[i] = i;
  }

  for(i = 0; i < 100; i++) {
    dest[i] = src[i];
  }
  i++;
  dest[i] = '\0'; //@violation OVERRUN.STATIC
}
