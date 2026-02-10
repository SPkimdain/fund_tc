struct TOS_002_Struct {
  char ch[100];
  int num[100];
};

void TOS_002_function(TOS_002_Struct *x){
  x->ch[200] = 'c'; //@violation TYPE_OVERRUN.STATIC
}

