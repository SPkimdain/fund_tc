// @checker UNMATCH_TYPE_PTR_SUBTRACT

enum { SIZE = 32 };


void func_bar(void)
{
  int arr1[10];
  int arr2[10];
 
  int *arr1_ptr = &arr1[0];
  int *arr2_ptr = &arr2[0];
  int arr3 = arr1_ptr - arr2_ptr;	//@violation UNMATCH_TYPE_PTR_SUBTRACT

  arr2_ptr = &arr1[1];
  arr3 = arr1_ptr - arr2_ptr;
}
 
void func_foo(void) {
  int nums[SIZE];
  int nums2[SIZE];
  char *c_str[SIZE];
  int *next_num_ptr = nums;
  int *next_num_ptr2 = nums2;
  int *next_num_ptr3 = nums;
  int free_bytes;

  free_bytes = next_num_ptr - next_num_ptr3;
  free_bytes = nums - next_num_ptr3;

  free_bytes = c_str - (char **)next_num_ptr;	//@violation UNMATCH_TYPE_PTR_SUBTRACT

  free_bytes = next_num_ptr - next_num_ptr2;	//@violation UNMATCH_TYPE_PTR_SUBTRACT
  
  next_num_ptr = nums2;

  free_bytes = next_num_ptr - next_num_ptr2;
}


void func_charlie(void)
{
	int nums[SIZE];
	int *next_num_ptr = nums;
	int free_bytes;

	/* Increment next_num_ptr as array fills */

	free_bytes = (&(nums[SIZE]) - next_num_ptr) * sizeof(int);
}