//@checker DEFINE_SET_NEW_HANDLER

void DEFSNH_001_function() {
  int* arr = new int[100]; //@violation DEFINE_SET_NEW_HANDLER
  
  
  delete[] arr;
}
