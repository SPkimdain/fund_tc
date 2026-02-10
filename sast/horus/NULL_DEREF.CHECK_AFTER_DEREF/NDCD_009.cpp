//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_009 - three null dereference2 from opus */
short NDCD_009_function(char** pp) {
  char*** ppp = &pp;
  
  ***ppp = 'a';

  if(**ppp) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    return 0;
  }

  return 1;
}

