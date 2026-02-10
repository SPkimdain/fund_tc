// @checker BYTE_COMPARISON_STRUCT

extern int memcmp ( const void * ptr1, const void * ptr2, int num );
extern int printf ( const char * format, ... );
extern void * memset ( void * ptr, int value, int num );

struct my_buf {
  char buff_type;
  int size;
  char buffer[50];
  char testarr[2];
};
 
int buf_equal(const struct my_buf *s1, 
               const struct my_buf *s2) 
{
  return 0 == memcmp(s1, s2, sizeof *s1);	//@violation	BYTE_COMPARISON_STRUCT
}
 
void f (void) {
  struct my_buf a = { 0, 0, "", "" };
  struct my_buf c = { 0, 0, "", "" };
  struct my_buf b;
  struct my_buf test = *&a;
 
  memset(&b, 0, sizeof(b));
 if( buf_equal(&a, &b) == 0 )
 {
	  /* ... */
   int x = 0;
 } 
 
 
if(memcmp(c.testarr, "01", 2) != 0) {  
   printf("not matched");
 }
 
 

 if(memcmp(&a, &b, sizeof(a)) != 0) {  //@violation	BYTE_COMPARISON_STRUCT
   printf("not matched");
 }

 if(!memcmp(&b, &a, sizeof(a))) {  //@violation	BYTE_COMPARISON_STRUCT
   printf("matched");
 }

 if(memcmp(&a, &b, sizeof(a))) {  //@violation	BYTE_COMPARISON_STRUCT
   printf("not matched");
 }
 

}
