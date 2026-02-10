//@checker FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT

void FWVRTSHESE_002_function(int* buf, int* stream, int len) { //It's ok.
  for (int i = 0; i < len; i++) {
    buf[i] = stream[i]; 
  }
}

void FWVRTSHESE_002_function2(int* buf, int* stream, int len) { //It's ok.
  int* ptr = stream;

  *ptr = 10;
}

void FWVRTSHESE_002_function3()  //@violation FUNCTION_WITH_VOID_RETURN_TYPE_SHOULD_HAVE_EXTERNAL_SIDE_EFFECT
{
  int local;
  local = 0;
}