//@checker DO_NOT_USE_DO_WHILE

void DNUDOWHILE_001_function (int k){
  
	do {	//@violation DO_NOT_USE_DO_WHILE
		k--;
	} while(k < 100);
  
  return;
}


