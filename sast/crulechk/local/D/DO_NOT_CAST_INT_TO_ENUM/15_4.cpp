//@checker DO_NOT_CAST_INT_TO_ENUM
enum Colours { RED, GREEN = 2, BLUE }; 
void bar() { 
  Colours colour = static_cast<Colours>( 1000 ); //@violation DO_NOT_CAST_INT_TO_ENUM
  if ( 1000 == colour ) {
    // may not be reached 
  } 
}

void foo() { 
  Colours colour = static_cast<Colours>( 1 ); //@violation DO_NOT_CAST_INT_TO_ENUM
  switch ( colour ) { 
  case RED:
  case GREEN: 
  case BLUE:
    break; 
  default:
    break; // value not handled 
  }
}
