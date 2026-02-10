// @checker COMPLEX_CONTROL_IN_SWITCH

int foo(int i) {
  int j=0;
  switch (i) {
    case 1:
      for(j=0;j<10;j++) {
      // No break, process case 2 as well
    case 2: //@violation		COMPLEX_CONTROL_IN_SWITCH
        j++;
      // No break, process case 3 as well
    case 3: //@violation		COMPLEX_CONTROL_IN_SWITCH
        j++;
      }
      break;
  default:
    // Default action
    break;
  }
  return j;
}

int bar()
{
	int count; /* Must be nonzero */
	char *to;     /* Output destination */
	char *from;   /* Points to count bytes to copy */
	 
	do {
	  *to = *from++;        /* Note that the "to" pointer is NOT incremented */
	} while (--count > 0);

	int n = (count + 7) / 8;
	switch (count % 8) {
	  case 0: do { *to = *from++;
	  case 7:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
	  case 6:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
	  case 5:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
	  case 4:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
	  case 3:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
	  case 2:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
	  case 1:      *to = *from++;	//@violation		COMPLEX_CONTROL_IN_SWITCH
			  } while (--n > 0);
	}

	switch (count % 8) {
	  case 0: *to = *from++; /* fall through */
	  case 7: *to = *from++; /* fall through */
	  case 6: *to = *from++; /* fall through */
	  case 5: *to = *from++; /* fall through */
	  case 4: *to = *from++; /* fall through */
	  case 3: *to = *from++; /* fall through */
	  case 2: *to = *from++; /* fall through */
	  case 1: *to = *from++; /* fall through */
	}
	while (--n > 0) {
	  *to = *from++;
	  *to = *from++;
	  *to = *from++;
	  *to = *from++;
	  *to = *from++;
	  *to = *from++;
	  *to = *from++;
	  *to = *from++;
	}
}