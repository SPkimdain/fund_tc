
/* UN_073 - array initialization */
void UN_073_function() {
  int arr[10] = { 1 };
  //arr[1~9] is 0
  int arr2[10] = { 1, };

  int un;

  int sum = 0;
  sum += arr[0];
  
  sum += arr[1]; //It's ok.

  sum += arr2[1]; //It's ok.

  sum += un; //@violation UNINIT
}
