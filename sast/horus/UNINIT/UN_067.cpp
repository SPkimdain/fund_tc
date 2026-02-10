#pragma warning(disable : 4700)

/* UN_067 - Lazy compound value */
struct UN_067_Struct {
  int x;
  int y;
  int z;
};

void UN_067_function1(UN_067_Struct* state, int& f) {
  f = 10;

  int a = 0;
  int b = 10;
  int c = 30;
  UN_067_Struct obj;
  obj.x = c;
  obj.y = 20;
  obj.z = f;
  
  *state = obj;
}


void UN_067_function2(int flag) {
  UN_067_Struct s;
  
  
  UN_067_function1(&s, flag);
  
  int ret = s.y; //It's ok.

  int a;
  int b;
  
  b = a; //@violation UNINIT

}
