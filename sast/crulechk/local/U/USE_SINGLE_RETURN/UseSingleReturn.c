//@checker USE_SINGLE_RETURN
int function(int cond) {	//@violation USE_SINGLE_RETURN
  if(cond > 20){
    return 20;
  } else{
    return 10;                 
  }
}