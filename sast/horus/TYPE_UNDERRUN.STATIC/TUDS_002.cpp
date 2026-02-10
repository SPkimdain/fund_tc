struct TUDS_002_Struct {
  char ch[100];
  int num[100];
};

void TUDS_002_function(TUDS_002_Struct *x){
  x->ch[-1] = 'c'; //@violation TYPE_UNDERRUN.STATIC
}

