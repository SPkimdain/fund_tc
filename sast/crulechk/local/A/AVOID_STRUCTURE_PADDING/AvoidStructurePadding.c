//@checker AVOID_STRUCTURE_PADDING
#define NULL 0
typedef unsigned long long uint64_t;

extern void * memset ( void * ptr, int value, int num );

extern int copy_to_user(void *dest, void *src, int size);
 
struct AVSTPAD_Struct2 {
  uint64_t rows;
  uint64_t cols;
  float anchors[6];
}AVSTPAD_Struct2;

struct AVSTPAD_Struct {
  int a;
  char b;	//@violation AVOID_STRUCTURE_PADDING
  int c;
}AVSTPAD_Struct;

 
void AVSTPAD_001_function() {
  struct AVSTPAD_Struct arg;
  
  void *usr_buf = NULL;
 
  memset(&arg, 0, sizeof(arg));
 
  arg.a = 1;
  arg.b = 2;
  arg.c = 3;
 
  copy_to_user(usr_buf, &arg, sizeof(arg));
}

int AVSTPAD_001_function2() {
	
  AVSTPAD_001_function();
	
	return 0;
}
