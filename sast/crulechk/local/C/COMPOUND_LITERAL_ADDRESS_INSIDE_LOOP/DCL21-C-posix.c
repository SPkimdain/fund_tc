//@checker COMPOUND_LITERAL_ADDRESS_INSIDE_LOOP
typedef struct int_struct {
  int x;
} int_struct;
 
#define MAX_INTS 10
 
void noncompliant(void){
  int i;
  int result;
  int_struct *ints[MAX_INTS];
 
  for (i = 0; i < MAX_INTS; i++) {
    ints[i] = &(int_struct){i};	//@violation COMPOUND_LITERAL_ADDRESS_INSIDE_LOOP
  }
 
  for (i = 0; i < MAX_INTS; i++) {
    result = ints[i]->x;
  }
}


void compliant(void){
  int i;
  int result;
  int_struct ints[MAX_INTS];
 
  for (i = 0; i < MAX_INTS; i++) {
    ints[i] = (int_struct){i};
  }
 
  for (i = 0; i < MAX_INTS; i++) {
    result = ints[i].x;
  }
}
