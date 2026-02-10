
/* UN_074 - array initialization2 */
void UN_074_function() {
  int arr[10] = { 1 };
  //arr[1~9] is 0
  int arr2[10] = { 1, };

  int un;

  int sum = 0;
  sum += arr[0];
  
  arr[0] = 10;
  
  sum += arr[1]; //It's ok.

  sum += arr2[1]; //It's ok.

  sum += un; //@violation UNINIT
}
