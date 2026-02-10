//@checker DO_NOT_USE_BREAK_CONTINUE
void function(){
	int index = 0;
	while(1){
		if(index == 10){
			break;                //@violation DO_NOT_USE_BREAK_CONTINUE
		}
		index++;
	}
}
