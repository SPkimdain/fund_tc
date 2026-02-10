
/* TOS_048 - member call */
class TOS_048_Class {
public:
  int valueReturn() { return 10; }

  void TOS_048_function() {
    p[this->valueReturn()] = 10; //@violation TYPE_OVERRUN.STATIC
  }

private:
  int p[10];
};

