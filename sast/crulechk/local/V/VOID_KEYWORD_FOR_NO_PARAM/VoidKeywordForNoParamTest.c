//@checker VOID_KEYWORD_FOR_NO_PARAM
struct ST {
  int value;
};

void function() { //@violation VOID_KEYWORD_FOR_NO_PARAM
  int x = 0;
}

void 
  function_another() { //@violation VOID_KEYWORD_FOR_NO_PARAM
  int x = 0;
}

void function2(void) { //It's ok.
  int x = 0;
}

void function3(int arg) {
  int x = 0;
}

void PrintF(ST* ptBody) {
  int x = 0;
}

void
complexIdFunc  () { //@violation VOID_KEYWORD_FOR_NO_PARAM
  int x = 0;
  x++;
}
