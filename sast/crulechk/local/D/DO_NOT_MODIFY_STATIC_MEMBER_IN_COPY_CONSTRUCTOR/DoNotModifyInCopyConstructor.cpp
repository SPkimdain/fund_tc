//@checker DO_NOT_MODIFY_STATIC_MEMBER_IN_COPY_CONSTRUCTOR

class A
{

public:
   A () {}
   A ( const A& rhs )
   : m_i (rhs.m_i)
   {
     ++m_static;  //@violation DO_NOT_MODIFY_STATIC_MEMBER_IN_COPY_CONSTRUCTOR
     --m_static_sec; //@violation DO_NOT_MODIFY_STATIC_MEMBER_IN_COPY_CONSTRUCTOR
   }
private:
  int m_i;
  static int m_static;
  static int m_static_sec;



};

int A::m_static = 0 ;
int A::m_static_sec = 1 ;

A f ()
{
  return A ();
}

void b ()
{
  A a = f () ;
}
