//@checker BAD_CALL.TYPE_MISMATCH.STRING

extern char * strncpy ( char * destination, const char * source, int num );
extern wchar_t* wcsncpy (wchar_t* destination, const wchar_t* source, int num); 
 
void BCTMMSTR_001_function1(void) {
  char narrow_str1[] = "01234567890123456789";
  char narrow_str2[] = "0000000000";
 
  wcsncpy(narrow_str2, narrow_str1, 10);	//@violation	BAD_CALL.TYPE_MISMATCH.STRING

}
