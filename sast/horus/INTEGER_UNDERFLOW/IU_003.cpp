
/* IU_003 switch branch */
void IU_003_function(int arg) {
  int si1 = -2147483647;
  int si2 = 0;
  
  switch(arg){
	case 0:
	case 1:
	case 2:
	  break;
	case 3:
	  si2 = 2;
	  break;
	default:
	  break;	
  }
  
  int result = si1- si2; //@violation INTEGER_UNDERFLOW
}
