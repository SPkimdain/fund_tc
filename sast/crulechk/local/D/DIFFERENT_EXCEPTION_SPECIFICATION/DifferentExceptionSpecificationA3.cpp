//@checker DIFFERENT_EXCEPTION_SPECIFICATION
extern void DIFEXSPEC_001_function() throw (int, float);


void DIFEXSPEC_003_caller( ) {
  DIFEXSPEC_001_function();
}
