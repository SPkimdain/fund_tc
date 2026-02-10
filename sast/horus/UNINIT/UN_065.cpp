
/* UN_065 - non-assign function */
struct UN_065_Struct {
  int x;
  int y;
};

int UN_065_function1(bool flag, UN_065_Struct* obj) {
  if(flag == true) {
    obj->x = 10;
    obj->y = 20;
    return 0;
  }
  else {
    return 1;
  }
}

void UN_065_function2(bool flag) {
  UN_065_Struct v;
  
  UN_065_function1(flag, &v);
  
  int ret = v.y; //@violation UNINIT
}
