//@checker DO_NOT_REUSE_IDENTIFIER_NAME

 namespace NS1{
   static int global = 0;
 }

 namespace NS2
 {
   void fn ()
   {
     int global; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
   }
 }
