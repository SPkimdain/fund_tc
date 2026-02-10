
/* LM_018 - new */
void LM_018_function() {
  char* ptr = new char[100];
  *ptr = 'a';
} //@violation LEAK.MEMORY

