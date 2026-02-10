// @checker DO_NOT_USE_THROWABLE_FUNCTION_IN_COPY_ASSIGNMENT

class A
{
  public:
    A& operator=( const A& rhs )
    {
	A temp( rhs );
	Swap( temp ); // @violation DO_NOT_USE_THROWABLE_FUNCTION_IN_COPY_ASSIGNMENT
	return *this;
    }

    A& operator=( A& rhs )
    {
	A temp( rhs );
	Swap( temp ); // @violation DO_NOT_USE_THROWABLE_FUNCTION_IN_COPY_ASSIGNMENT
	return *this;
    }



  private:
    void Swap( A& rhs ) throw ();
};
