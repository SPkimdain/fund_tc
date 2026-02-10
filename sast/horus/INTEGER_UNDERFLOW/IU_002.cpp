
/* IU_002 if branch */
void IU_002_function(int arg) {
  int si1 = -2147483647;
  int si2 = 2;
  int result = 0;
  if(arg == 10) {
	  result = si1 + si2;
  }
  else{
	  result = si1 - si2; //@violation INTEGER_UNDERFLOW
  }
}
