//@checker EMPTY_WHILE

void emptyWhileTest(register int k) {
  volatile int x = 1;
  volatile int y = 1;
  volatile int z = 1;

  while(x + y - z + k); //@violation EMPTY_WHILE

  while(1)  //@violation EMPTY_WHILE
  {}


  while(1)    
  {
     while(x + y - z + k); //@violation EMPTY_WHILE
	
  }

  while(x + y - z + k); //@violation EMPTY_WHILE

  
 
 while(1)  
 {
	  while(1)  //@violation EMPTY_WHILE
	  {}

 }
}
