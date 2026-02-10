/* IUOPN_002 - alignas */

void* operator new(unsigned int size, void* ptr);

void IUOPN_002_function() {
  
  char c; // Used elsewhere in the function
  
  unsigned char buffer[sizeof(long)];
  
  long* lp = ::new(buffer) long; //@violation INCORRECT_USE_OF_PLACEMENT_NEW


  alignas(long) unsigned char buffer2[sizeof(long)];
  long* lp2 = ::new(buffer2) long; //It's ok.
}

