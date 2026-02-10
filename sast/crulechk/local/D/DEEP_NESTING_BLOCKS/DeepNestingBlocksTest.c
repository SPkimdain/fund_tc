//@checker DEEP_NESTING_BLOCKS
void DPNBLK_001_function(int p1, int p2){
	if(p1){
		int i = 0;
		for(i = 0; i < 100; i++){
      if(p2 > 10) {
        if(i == 5){	//@violation DEEP_NESTING_BLOCKS
          return;
        }
      }
		}
	}
}