
void MNATD_001_function(){
  char *p = new char[4];
  delete p;  //@violation MISMATCH.NEW_ARRAY_TO_DELETE
}

