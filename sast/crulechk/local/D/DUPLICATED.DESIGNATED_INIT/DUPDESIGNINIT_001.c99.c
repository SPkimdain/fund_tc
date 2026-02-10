//@checker DUPLICATED.DESIGNATED_INIT

void DUPDESIGNINIT_001_function() {
	int a2[5] = { [0] = -5, [1] = -4, [2] = -3, };
  int a3[5] = { [0] = -5, [1] = -4, [2] = -3, [2] = -2, [4] = -1 };         //@violation DUPLICATED.DESIGNATED_INIT
  int a4[5] = { [0] = -5, [1] = -4, [2] = -3, [2] = -2, [2] = -1 };         //@violation DUPLICATED.DESIGNATED_INIT
}

struct DUPDESIGNINIT_001_Struct{
	int a;
	int b;
	int c;
	int d;
};


void DUPDESIGNINIT_001_function2(void)
{
	struct DUPDESIGNINIT_001_Struct s1 = {.a =100, .b = 10, .c = 5, .d = -1 };
	struct DUPDESIGNINIT_001_Struct s2 = {.a =100, .b = 10, .a = 5, .d = -1 };	// @violation DUPLICATED.DESIGNATED_INIT
}
