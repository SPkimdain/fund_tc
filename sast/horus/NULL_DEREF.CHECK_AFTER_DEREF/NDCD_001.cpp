//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_001 - Very simple null dereference. */
void NDCD_001_function(int* p) {
  *p = 100; 

  if (p){ //@violation NULL_DEREF.CHECK_AFTER_DEREF
	  int i = 0;
  }
}
