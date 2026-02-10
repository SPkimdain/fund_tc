/* MR_004 - class2 */

class MR_004_Class {
public:
  MR_004_Class() : value(10) {
    value++;
  }

private:
  int value;
};

MR_004_Class MR_004_function(int offset) {
  MR_004_Class obj;

  switch(offset) {
  case 0:
    return obj;
  case 1:
    break;
  }
} //@violation MISSING_RETURN

