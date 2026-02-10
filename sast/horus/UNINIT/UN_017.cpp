
/* UN_017 - unary operator order */
void UN_017_function() {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  int* arr[2];

  arr[0] = &p;

  int index = 0;

  ptr = arr[index++]; // index + 1 after assign arr[0].

  ret += *ptr; // No problem;

  index = 0;
  
  // assign arr[1] after index + 1.	
  ptr = arr[++index]; // @violation UNINIT
  ret += *ptr; 
}
