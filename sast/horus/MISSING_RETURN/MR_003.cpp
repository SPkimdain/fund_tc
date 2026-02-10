/* MR_003 - class member function */

class MR_003_Class {
public:
  MR_003_Class() : value(10) {
    value++;
  }

  char MR_003_function(int offset);

private:
  int value;
};

char MR_003_Class::MR_003_function(int offset) {
  int mrValue = value + offset;
  if(mrValue == 10) {
    return 5;
  }
  else if(mrValue == 5) {
    return 3;
  }
  else {

  }
} //@violation MISSING_RETURN

