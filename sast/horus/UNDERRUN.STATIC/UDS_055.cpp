
/* UDS_055 - Simple case */
void UDS_055_function() {
  int buf[5];

  int ret = 0;
  int i = 0;
  for(i = 100; i > 0; i--) {
    ret++;
  }

  buf[i - 1] = 10; //@violation UNDERRUN.STATIC
}
