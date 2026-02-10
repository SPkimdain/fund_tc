//@checker DO_NOT_CAST_TO_AN_OUT_OF_RANGE_ENUM_VALUE
enum EnumType {
  First,
  Second,
  Third
};

void DNCTAOOREV_func(int intVar) {
  EnumType enumVar = static_cast < EnumType > (intVar);		//@violation DO_NOT_CAST_TO_AN_OUT_OF_RANGE_ENUM_VALUE
  if (enumVar < First || enumVar > Third) {
    // Handle error
  }
}