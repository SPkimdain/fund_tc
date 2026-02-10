// @checker CONCATENATE_DIFF_TYPE_STR

 const char *features = "t"
#ifdef MAKE_SYMLINKS
						" test"
						"MAKELEVEL"
#endif
;

void CONCATDIFFT_001_function(){
  wchar_t *msg = L"This message is very long, so I want to divide it " "into two parts.";	//@violation	CONCATENATE_DIFF_TYPE_STR
  wchar_t *msg2 = "This message is very long, so I want to divide it " L"into two parts.";	//@violation	CONCATENATE_DIFF_TYPE_STR
	wchar_t *msg3 = L"This message is very long, so I want to divide it "	
						"into two parts.";	//@violation	CONCATENATE_DIFF_TYPE_STR

	char *msg4 = "asdadadassda"
						"dsfsdfdsfdfsdf";

	wchar_t *msg5 = L"asdf"
						L"aaaaa";
						
}
