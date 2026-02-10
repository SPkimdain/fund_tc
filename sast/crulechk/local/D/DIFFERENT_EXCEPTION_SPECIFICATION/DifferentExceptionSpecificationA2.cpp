//@checker DIFFERENT_EXCEPTION_SPECIFICATION
extern void DIFEXSPEC_001_function() throw (const char*);


void DIFEXSPEC_002_caller( ) {
  DIFEXSPEC_001_function();
}
