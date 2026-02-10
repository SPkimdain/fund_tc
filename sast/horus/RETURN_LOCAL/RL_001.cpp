
/* RL_001 - RETURN_LOCAL simple example */


int* RL_001_function() {
  int arr[100];
  for(int i = 0; i < 100; i++){
	  arr[i] = i;
  }
  return arr; //@violation RETURN_LOCAL
}

