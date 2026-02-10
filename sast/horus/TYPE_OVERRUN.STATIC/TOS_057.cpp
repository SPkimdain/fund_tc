
/* TOS_057 - boundary index */
struct TOS_057_Struct {
  int a[10];
};


void TOS_057_function(int value) {
  TOS_057_Struct obj;
  if(value > 10) { //Wrong check.
    obj.a[value] = 10; //@violation TYPE_OVERRUN.STATIC
  }
}

