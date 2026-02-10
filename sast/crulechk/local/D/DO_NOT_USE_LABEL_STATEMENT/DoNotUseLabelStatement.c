//@checker DO_NOT_USE_LABEL_STATEMENT

extern int printf ( const char * format, ... );
typedef signed int SINT_32;

void static_111(void)
{
   SINT_32 jump_flag = 0;
start:	//@violation	DO_NOT_USE_LABEL_STATEMENT
   jump_flag++;
   if (jump_flag <10)
   {
      goto start;
   }

   switch(jump_flag)
   {
   case 1:
	   printf("this is one!");
	   break;
   case 2:
	   printf("this is two!");
	   break;
   default:
	   break;
   }
}
