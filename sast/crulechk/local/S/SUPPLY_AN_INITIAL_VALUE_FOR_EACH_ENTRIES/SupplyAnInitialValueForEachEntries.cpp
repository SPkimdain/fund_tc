//@checker SUPPLY_AN_INITIAL_VALUE_FOR_EACH_ENTRIES
class B {};
class VB : public virtual B {};
class C {};
class CC : public B {};
class DC : public VB, public C
{
 public:
  DC()
      : B(), VB(), C(), i( 1 ), c() // correct order of initialization
  {}
 private:
  int i;
  C c;
};


class DD : public CC {
  public:
    DD() {}	//@violation SUPPLY_AN_INITIAL_VALUE_FOR_EACH_ENTRIES
};
