
/* UDS_049 - trygraphs */
void UDS_049_function(int flag) {
  int p[10] = { 0, };
  int value = 10;
  int index = (flag == 10) ? 5 : -1;
  
  p[index] = 100; //@violation UNDERRUN.STATIC
}

