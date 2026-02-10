//@checker CONST_IN_LOOP_TEST
void ConstInLoopTestBad(void){
	while(5)	//@violation CONST_IN_LOOP_TEST
	{
		//Do something
	}
}

void ConstInLoopTestGood(int index){
	while(index < 10)	
	{
		//Do something
	}
}