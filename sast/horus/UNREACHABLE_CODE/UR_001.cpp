//@checker UNREACHABLE_CODE
enum light { red, amber, red_amber, green };

void UR_001_function(enum light c) {
  enum light res;

  switch(c) {
  case red:
    res = red_amber;
    break;
  case red_amber:
    res = green;
    break;
  case green:
    res = amber;
    break;
  case amber:
    res = red_amber;
    break;
  default:	//@violation UNREACHABLE_CODE
    int a = 1;  
    break;
  }
}
