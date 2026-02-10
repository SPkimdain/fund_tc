//@checker HANDLE_STANDARD_LIBRARY_ERROR

#define NULL 0
#define size_t int
#define wchar_t char

extern size_t mbstowcs (wchar_t* dest, const char* src, size_t max);
extern char* setlocale (int category, const char* locale);
  
int utf8_to_wcs(wchar_t *wcs, size_t n, const char *utf8,
                size_t *size) {
  if (NULL == size) {
    return -1;
  }
  setlocale(1, "en_US.UTF-8"); //@violation HANDLE_STANDARD_LIBRARY_ERROR
  *size = mbstowcs(wcs, utf8, n);
  return 0;
}