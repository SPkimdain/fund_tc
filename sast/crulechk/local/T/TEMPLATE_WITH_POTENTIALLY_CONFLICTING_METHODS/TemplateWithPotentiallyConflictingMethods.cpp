// @checker TEMPLATE_WITH_POTENTIALLY_CONFLICTING_METHODS

template< typename T >
class A
{
  public:
  void foo( T );       // @violation TEMPLATE_WITH_POTENTIALLY_CONFLICTING_METHODS
    void foo( int );
};
// template class A< int >;
// error void foo(int) declared twice
