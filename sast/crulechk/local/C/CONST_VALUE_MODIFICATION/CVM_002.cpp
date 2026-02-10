// @checker CONST_VALUE_MODIFICATION


void CVM_002_function(char c) {
  char &const p = c; //@violation CONST_VALUE_MODIFICATION

  const char& p2 = c; //It's ok.

}
