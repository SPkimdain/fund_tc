//@checker DO_NOT_OVERLOAD_LAND_LOR_COMMA
class Time
{
 public:
  const Time operator +(const Time &t) const {
    Time newT;
    newT.data = this->data + t.data;
    return newT;
  }

  const Time operator &&(const Time &t) const {	//@violation DO_NOT_OVERLOAD_LAND_LOR_COMMA
    Time newT;
    return newT;
  }


 private:
  int data;
};


Time operator||(const Time& a, const Time& b) {	//@violation DO_NOT_OVERLOAD_LAND_LOR_COMMA
  Time newT;
  return newT;
}
