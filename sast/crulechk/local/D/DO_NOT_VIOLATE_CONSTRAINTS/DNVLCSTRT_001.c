//@checker DO_NOT_VIOLATE_CONSTRAINTS

static int i = 12; //@b-violation DO_NOT_VIOLATE_CONSTRAINTS


extern inline void DNVLCSTRT_001_function(int a) { //@violation DO_NOT_VIOLATE_CONSTRAINTS
  int b = a * i;
  /* ... */
}

extern inline void DNVLCSTRT_001_function2(void) { //@violation DO_NOT_VIOLATE_CONSTRAINTS
  static int ii = 12; //@b-violation DO_NOT_VIOLATE_CONSTRAINTS
  /* Perform calculations which may modify i */
  int x = ii + 5;
}


extern inline void DNVLCSTRT_001_function3(int a) {
	int y = 0;
	y++;
}



void DNVLCSTRT_001_function4(int a) {
	int z = i; 
}


inline void DNVLCSTRT_001_function5()
{
	int z = i;
}

extern inline void DNVLCSTRT_001_function6() //@violation DO_NOT_VIOLATE_CONSTRAINTS
{
	static int iii = 10; //@b-violation DO_NOT_VIOLATE_CONSTRAINTS
	int k = i - iii + 5;
}

