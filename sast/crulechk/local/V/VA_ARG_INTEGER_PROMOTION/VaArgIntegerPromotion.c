//@checker VA_ARG_INTEGER_PROMOTION

#include <stdarg.h>

void VARGPMT_001_function(size_t num_vargs, ...) {
  va_list ap;
  va_start(ap, num_vargs);
  if(num_vargs > 0) {
    unsigned char c = va_arg(ap, unsigned char); //@violation VA_ARG_INTEGER_PROMOTION
  }
  va_end(ap);
}
