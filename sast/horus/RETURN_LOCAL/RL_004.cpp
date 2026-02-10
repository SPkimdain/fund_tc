
/* RL_004 - RETURN_LOCAL simple example */


int* RL_004_function() {
  int arr[100];
  for(int i = 0; i < 100; i++){
	  arr[i] = i;
  }
  return arr+1; //@violation RETURN_LOCAL
}


