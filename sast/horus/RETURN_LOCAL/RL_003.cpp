
/* RL_003 - RETURN_LOCAL multiple return */


char* RL_003_function(int flag, char* p) {
  char str1[4] = "abc";
  
  if(flag > 10){
    return p;
  }
  else{
    return str1; //@violation RETURN_LOCAL
  }
}

