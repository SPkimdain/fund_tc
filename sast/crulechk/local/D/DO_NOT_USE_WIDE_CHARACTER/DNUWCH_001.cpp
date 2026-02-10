// @checker DO_NOT_USE_WIDE_CHARACTER

#include <stdio.h>
#include <wchar.h>

int DNUWCH_001_function() {
	wchar_t chr;
	wchar_t *text;
	
	chr = L'Y'; // @violation DO_NOT_USE_WIDE_CHARACTER
	text = L"REAllOC"; // @violation DO_NOT_USE_WIDE_CHARACTER
	
	wprintf(L"%c\n", chr); // @violation DO_NOT_USE_WIDE_CHARACTER
	wprintf(L"%s\n", text); // @violation DO_NOT_USE_WIDE_CHARACTER
	return 1;
}
