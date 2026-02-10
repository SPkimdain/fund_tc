// @checker OPERATOR_NEW_AND_DELETE_MISMATCHED

#include <cstddef>

class ONADM_1
{
 public:
  void* operator new(size_t)  { return 0;}
  void operator delete(void*) { return;}            // got proper match

 private:
  int dummy;
};


class ONADM_2
{
 public:
  void* operator new(size_t) { return 0; }    // @violation OPERATOR_NEW_AND_DELETE_MISMATCHED

 private:
  int dummy;
};


//global
void *operator new( size_t size, void *p )     // @violation OPERATOR_NEW_AND_DELETE_MISMATCHED
{ return p; }
