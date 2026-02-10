// @checker INSUFFICIENT_INIT_ARRAY

typedef signed int int32_t;
typedef struct MyStruct
{
  int32_t x1;
  int32_t x2;
  int32_t x3;
} MyStruct;

typedef struct MyStruct2
{
  MyStruct y3;	// 3
  MyStruct y4[3];	// 9
  int32_t y1;		//1
  int32_t y2[3];	//3
} MyStruct2;


void foo (void)
{
	int32_t my_array1[10] = {0,};	// NOT violation. zero-initialize array
	int32_t my_array4[4] = {1,2,3,4};
	MyStruct my_array5[3] = {1,2,3,4,5,6,7,8,9};
	MyStruct2 my_array6[2] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int32_t my_array[3] = { 1, 2 };  //@violation INSUFFICIENT_INIT_ARRAY
	MyStruct my_array2[2] = { 0, 0, 0};	//@violation INSUFFICIENT_INIT_ARRAY		
	MyStruct2 my_array3[4] = {1, 2, 3, 4};	//@violation INSUFFICIENT_INIT_ARRAY
	
}