
/* DF_006 - new/delete */
void DF_006_function() {
  int* ptr = new int(10);
  delete ptr;
  delete ptr; //@violation DOUBLE_FREE
}
