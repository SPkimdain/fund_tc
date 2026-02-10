//@checker POSTPONE_VARIABLE_DEFINITIONS

void PSTPVDEF_001_function(int flag, int len) {

  int y = 0; //@violation POSTPONE_VARIABLE_DEFINITIONS
  if (flag > 10) {
    int x = 0;
    for (auto&& i = 0; i < 10; i++)  {
      x++; //It's ok.
    }

    for (auto&& i = 0; i < 20; i++) {
      int k = 0;
      if (flag > 5) {
        int yy = 0;
        k++;
      }      
    }

    if (flag > 5) {
      y++;
    }

  }
}
