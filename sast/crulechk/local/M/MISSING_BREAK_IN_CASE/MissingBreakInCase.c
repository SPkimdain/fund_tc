// @checker MISSING_BREAK_IN_CASE

extern int printf ( const char * format, ... );
enum WidgetEnum { WE_W, WE_X, WE_Y, WE_Z } widget_type;


void foo()
{
	widget_type = WE_X;
	switch (widget_type) {
	  case WE_W:
		printf("asd");	//@violation MISSING_BREAK_IN_CASE
	  case WE_X:
		printf("aaa");
		break;
	  case WE_Y: 
	  case WE_Z:
		printf("aaaa");
		break;
	  default: /* can't happen */
		 printf("error");
	}
	printf("qweqweq");
}