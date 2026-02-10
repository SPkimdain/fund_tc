
/* TOBC_012 - functions */
class TOBC_012_Class {
  void TOBC_012_function1(int index) {
    arg[index] = 10;
  }

  unsigned TOBC_012_function2(unsigned value, bool flag) {
    if(flag == true) {
      return value + 5;
    }
    else {
      return value;
    }
  }

  void TOBC_012_function3(int idx) {
    if(idx < 9) { //[min, 8]
      TOBC_012_function1(TOBC_012_function2(idx, false)); //It's ok.

      TOBC_012_function1(TOBC_012_function2(idx, true)); //@violation TYPE_OVERRUN.BAD_COND
    }
  }

private:
  int arg[10];
};
