//@checker EXPLICIT_NAME_QUALIFIER_WHEN_TEMPLATED_BASE

class base {
     protected:
       int  abf;
     };


class deriv : public base {
      void aproc()
      {
        abf = 77;
        this-> abf = 0;  /* compliant */



        base::abf = 66; //base::()(super)this)->abf
        deriv::abf=88;

         base::abf = 79;  /* compliant */

      }
   };




namespace NS {
  typedef float TYPE;
} /*NS */


typedef int TYPE;
void g();

template <typename T>
class B;

template <typename T>
class A : public B<T>
{
public:
  int aa;

  void f1()
  {

    aa = 5; //@violation EXPLICIT_NAME_QUALIFIER_WHEN_TEMPLATED_BASE

    ::g ( ) ;
    g ( ) ; //@violation EXPLICIT_NAME_QUALIFIER_WHEN_TEMPLATED_BASE

    NS::TYPE t2 = 0;
    ::TYPE t1 = 0;
    TYPE t = 0;

  }
  void f2()
  {
    ::TYPE t1 = 0;
    ::g ( ) ;
    typename B<T>::TYPE t2 =0;
    this->g(); //@violation EXPLICIT_NAME_QUALIFIER_WHEN_TEMPLATED_BASE
  }
};

template <typename T>
class B
{
public:
  typedef T TYPE;
  TYPE b;
  void g();
};
template class A<int>;
