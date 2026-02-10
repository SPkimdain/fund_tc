//@checker DO_NOT_THROW_ITSELF_CAUSE_EXCEPTION
class E
{
public:
  E () {}
};

class E2
{
public:
  E2()
  {
    throw 10; //@b-violation DO_NOT_THROW_ITSELF_CAUSE_EXCEPTION

  }
};



int test()
{

  try
  {
    throw E ();
  }
  catch( ... )
  {

  }


  try
  {
    throw E2 (); //@violation DO_NOT_THROW_ITSELF_CAUSE_EXCEPTION
  }
  catch( ... )
  {

  }
}
