
/* ND_067 - function instantiation. */

int ND_067_function2(char* ptr){
	if(!ptr){
		return 0;
	}
	if(!*ptr){
		return 1;
	}
	return 2;
}

void ND_067_function(char* p) {
  if(p){
	  return;
  }
  
  int i = ND_067_function2(p); //It's ok.
  
  int* ptr = 0;
  *ptr = 100; //@violation NULL_DEREF
}
