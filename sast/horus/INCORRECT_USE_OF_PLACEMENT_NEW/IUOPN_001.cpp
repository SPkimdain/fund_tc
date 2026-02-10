
/* IUOPN_001 - simple case1 */
void* operator new(unsigned int size, void* ptr);

void IUOPN_001_function() {
  short s;
  long * lp = ::new(&s) long; //@violation INCORRECT_USE_OF_PLACEMENT_NEW

  long buffer;
  long* lp = new(&buffer) long; //It's ok.

}

