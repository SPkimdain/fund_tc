//@checker RELATIONSHIPS_IN_CONSTANT_DEFINITIONS

enum { ADULT_AGE=18 };
 
/* misleading, relationship established when none exists */
enum { ALCOHOL_AGE=ADULT_AGE+3 };	//@violation RELATIONSHIPS_IN_CONSTANT_DEFINITIONS
