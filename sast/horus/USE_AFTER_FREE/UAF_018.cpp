
/* UAF_018 - new */
void UAF_018_function() {
  char* ptr = new char[100];
  delete[] ptr;
  
  *ptr = 'a'; //@violation USE_AFTER_FREE
}

