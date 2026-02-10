//@checker LOGICAL_OP_SHALL_BE_PRIMARY_EXPR

#define CHECK_TEST(x) if((x) > 0 && (x) < 10) x++

int losbpe(int arg) {
  if(arg > 0 && arg < 10) { //@violation LOGICAL_OP_SHALL_BE_PRIMARY_EXPR
    return 10;
  } else if((arg > 0) && (arg < 40)) { //It's ok.
    return 5;
  }
  
  CHECK_TEST(arg); //It's ok. skip a macro.
  
  return 0;
}



typedef struct {
    int s1;
    int s2;    
}my_struct;

int losbpe2(int arg) {
    int arr[10] = {0,};
    my_struct st = {1,2};
  if(arg >= (long)st.s1 && arr[0] != 10) { //@violation LOGICAL_OP_SHALL_BE_PRIMARY_EXPR
    return 10;
  }
  else{
      return 0;
  }

  if(st.s1 < arg && st.s2 > arg && st.s1 > 10){ //@violation LOGICAL_OP_SHALL_BE_PRIMARY_EXPR

  }else{
      ;
  }

  return 0;
}