//@checker DECREMENT_ON_BOOLEAN

void DECONBOOL_001_function(bool flag) {
  flag--; //compile error in modern gcc, msvc
}

