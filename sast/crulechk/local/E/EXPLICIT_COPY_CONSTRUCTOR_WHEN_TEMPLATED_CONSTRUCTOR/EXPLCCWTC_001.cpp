//@checker EXPLICIT_COPY_CONSTRUCTOR_WHEN_TEMPLATED_CONSTRUCTOR

class EXPLCCWTC_001_A
{
public:
  EXPLCCWTC_001_A();

  template<typename T>
  EXPLCCWTC_001_A(T const   & );

private:
  int * i;
};

template<typename T>
EXPLCCWTC_001_A::EXPLCCWTC_001_A(T const & rhs) : i (new int) //@violation EXPLICIT_COPY_CONSTRUCTOR_WHEN_TEMPLATED_CONSTRUCTOR
{
  *i = *rhs.i;
}





class EXPLCCWTC_001_B
{
public:
  EXPLCCWTC_001_B();

  template<typename T>
  EXPLCCWTC_001_B(T const &rhs) //@violation EXPLICIT_COPY_CONSTRUCTOR_WHEN_TEMPLATED_CONSTRUCTOR
   : i (new int)
   {
     *i = *rhs.i;
   }

private:
  int * i;
};





void EXPLCCWTC_001_function(EXPLCCWTC_001_A const & a1, EXPLCCWTC_001_B& b1)
{
  EXPLCCWTC_001_A a2(a1);
  EXPLCCWTC_001_B b2(b1);
}
