#pragma warning(disable : 4700)

/* UN_068 - Lazy compound value */
struct UN_068_Struct {
  int a;
  char *b;
};

struct UN_068_Struct UN_068_global = { 10, 0 };

void UN_068_function1(UN_068_Struct* str){
  *str = UN_068_global;
}

void UN_068_function2(){

  UN_068_Struct str;
  UN_068_Struct str2;

  UN_068_function1(&str);

  int c = str.a + 1; //It's ok.
  
  int d = str2.a + 1; //@violation UNINIT
}

