//@checker DECLARE_VARIABLE_IN_MIDDLE_OF_BLOCK

void DVIMOB_001_function(int flag) {
  int x = 0;
  if(flag > 10) {
    int y = 0;
  }

  int z = 10; //@violation DECLARE_VARIABLE_IN_MIDDLE_OF_BLOCK

}
