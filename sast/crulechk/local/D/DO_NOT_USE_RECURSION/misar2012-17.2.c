//@checker DO_NOT_USE_RECURSION 

static int fn_a ( int parama )
{
   int ret_val;
   if ( parama > 0 )
   {
      ret_val = parama * fn_a ( parama - 1 ); //@violation DO_NOT_USE_RECURSION
   }
   else
   {
      ret_val = parama;
   }
   return ret_val;
}