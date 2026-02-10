
/* UN_066 - assign dereference value(function call) */
struct UN_066_Struct {
  int x;
  int y;
};

int UN_066_function1(UN_066_Struct* length) {
  if(length != 0) {
    length->x = 10;
  }
  else {}
  
  return 10;
}

void UN_066_function2(bool flag) {
  UN_066_Struct obj;
  
  int ret1 = UN_066_function1(&obj);
  
  int ret2 = obj.x; //It's ok.
  
  int ret3 = obj.y; //@violation UNINIT
}
