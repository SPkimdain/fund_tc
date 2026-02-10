//@checker INCREMENT_ON_BOOLEAN
void foo() {
  bool b = true;
  
  b++;	//@violation INCREMENT_ON_BOOLEAN
  ++b;	//@violation INCREMENT_ON_BOOLEAN
}
