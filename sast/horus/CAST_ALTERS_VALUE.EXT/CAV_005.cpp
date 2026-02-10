/* explicit constant, signed -> unsigned */

class CAV_005_Test {
public:
  CAV_005_Test() : value(0U) {}

  void CAV_005_Function() {
    value = -50; //@violation CAST_ALTERS_VALUE.EXT
  }
private:
  unsigned int value;
};
