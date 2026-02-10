

/* UDS_002 - boundary */
void UDS_002_function() {
  int value[10] = { 0, };  
  int index = 9;
  value[index] = 20; /* It's ok. */
  
  index = -1;
  value[index] = 21; //@violation UNDERRUN.STATIC
}
