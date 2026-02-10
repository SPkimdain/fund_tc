//@checker BAD_NAME.DUPLICATED

void function(int duplName, int flag) {
  if(flag > 10) {

    char duplName = 'x'; //@violation BAD_NAME.DUPLICATED
  }

}
