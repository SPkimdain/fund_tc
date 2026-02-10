//@checker MUTUALLY_VISIBLE_ID_SHOULD_BE_UNIQUE
extern int *global_symbol_definition_lookup_table_a;	
extern int *global_symbol_definition_lookup_table_b; //@violation MUTUALLY_VISIBLE_ID_SHOULD_BE_UNIQUE


extern int *a_global_symbol_definition_lookup_table;
extern int *b_global_symbol_definition_lookup_table;


/* extern int *\U00010401\U00010401\U00010401\U00010401; */
/* extern int *\U00010401\U00010401\U00010401\U00010402; */



/* extern int *\U00010401\U00010401\U00010401\U00010401; */
/* extern int *\U00010402\U00010401\U00010401\U00010401; */

static int *abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_a;


void foo() {
  int *abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_b;	//@violation MUTUALLY_VISIBLE_ID_SHOULD_BE_UNIQUE
  for(;;) {
    int *abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_abcd_c;
  }
}
