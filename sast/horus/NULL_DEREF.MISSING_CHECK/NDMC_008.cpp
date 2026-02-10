
/* NDMC_008 - unary operator order */
void NDMC_008_function(int* out) {
  int p = 10;
  int* ptr = 0;
  int ret = 0;
  int* arr[2];

  arr[0] = &p;
  arr[1] = out;

  if(out != 0) { //Check.
    *out++;
  }

  int index = 0;

  ptr = arr[index++]; // index + 1 after assign arr[0].

  ret += *ptr; // No problem;

  index = 0;
  ptr = arr[++index]; // assign arr[1] after index + 1.
  
  ret += *ptr; // @violation NULL_DEREF.MISSING_CHECK
}
