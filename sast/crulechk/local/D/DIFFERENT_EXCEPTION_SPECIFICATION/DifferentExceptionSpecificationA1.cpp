//@checker DIFFERENT_EXCEPTION_SPECIFICATION

void DIFEXSPEC_001_function() throw (int) { //@global-violation DIFFERENT_EXCEPTION_SPECIFICATION
	throw 12;
}


void DIFEXSPEC_001_caller( ) {
	char b;
  DIFEXSPEC_001_function();
}

