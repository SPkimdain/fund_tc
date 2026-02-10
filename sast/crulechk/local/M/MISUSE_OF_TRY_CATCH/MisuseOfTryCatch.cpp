//@checker MISUSE_OF_TRY_CATCH


void MOTC( int x)
{
  try
  {
    if ( x == 1 )
    {
        throw(1); //@violation MISUSE_OF_TRY_CATCH
    }
  }
  catch( int e)
  {
    //else
  }

}
