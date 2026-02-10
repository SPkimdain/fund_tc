
/* TUDS_048 - member call */
class TUDS_048_Class {
public:
  int valueReturn() { return -5; }

  void TUDS_048_function() {
    p[this->valueReturn()] = 10; //@violation TYPE_UNDERRUN.STATIC
  }

private:
  int p[10];
};

