
/* TUDBC_012 - functions */
class TUDBC_012_Class {
  void TUDBC_012_function1(int index) {
    arg[index] = 10;
  }

  int TUDBC_012_function2(int value, bool flag) {
    if(flag == true) {
      return value + 5;
    }
    else {
      return value;
    }
  }

  void TUDBC_012_function3(int idx) {
    if(idx >= 0 && idx < 5) { //[0, 4]
      idx -= 1; // [-1, 3]
      TUDBC_012_function1(TUDBC_012_function2(idx, true)); //It's ok.

      TUDBC_012_function1(TUDBC_012_function2(idx, false)); //@violation TYPE_UNDERRUN.BAD_COND
    }
  }

private:
  int arg[10];
};
