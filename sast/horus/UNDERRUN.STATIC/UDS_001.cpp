
/* UDS_001 - Simple case */
void UDS_001_function() {
  int buf[5];

  buf[-1] = 10; //@violation UNDERRUN.STATIC
}
