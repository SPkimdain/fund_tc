//@checker EMPTY_CATCH_BLOCK

int EMPTCBLK_001_function(int flag){
   try {
	   if(flag > 10) {
       int errCode = 15;
		   throw errCode;
	   }
   } catch (int exception) {        //@violation EMPTY_CATCH_BLOCK
          // Do nothing
   }
   
   return 0;
}
