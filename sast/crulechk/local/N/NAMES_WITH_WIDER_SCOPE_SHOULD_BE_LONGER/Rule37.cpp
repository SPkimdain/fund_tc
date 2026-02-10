//@checker NAMES_WITH_WIDER_SCOPE_SHOULD_BE_LONGER

int point;
int position;
int globalVariable;
int global_variable;
int x;

void foo() {
  int localPoint;    
  int local_point;   //@violation NAMES_WITH_WIDER_SCOPE_SHOULD_BE_LONGER
  int localPosition; 
  int local_position;//@violation NAMES_WITH_WIDER_SCOPE_SHOULD_BE_LONGER
  int xyro;
}
