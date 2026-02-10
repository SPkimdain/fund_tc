// @checker DO_NOT_DECLARE_OR_DEFINE_RESERVED_ID

#define 	PRIdFAST16   "d"

typedef long size_t;

extern int sprintf ( char * str, const char * format, ... );
extern int snprintf ( char * s, size_t n, const char * format, ... );

// non-compliant part

static const size_t _max_limit = 1024;  // @violation DO_NOT_DECLARE_OR_DEFINE_RESERVED_ID
size_t _limit = 100;                    // @violation DO_NOT_DECLARE_OR_DEFINE_RESERVED_ID

unsigned int noncompliant_getValue(unsigned int count) {
    return count < _limit ? count : _limit;
}


// compliant part

static const size_t max_limit = 1024;
size_t limit = 100;

unsigned int compliant_getValue(unsigned int count) {
    return count < limit ? count : limit;
}


// non-compliant part

static const int INTFAST16_LIMIT_MAX = 12000;  // @violation DO_NOT_DECLARE_OR_DEFINE_RESERVED_ID

void noncompliant_print_fast16(int val) {
    enum { MAX_SIZE = 80 };
    char buf [MAX_SIZE];
    if (INTFAST16_LIMIT_MAX < val)
	sprintf(buf, "The value is too large");
    else
	snprintf(buf, MAX_SIZE, "The value is %" PRIdFAST16, val);
    // ...
}


// compliant part

static const int MY_INTFAST16_UPPER_LIMIT = 12000;

void compliant_print_fast16(int val) {
    enum { BUFSIZE = 80 };
    char buf [BUFSIZE];
    if (MY_INTFAST16_UPPER_LIMIT < val)
	sprintf(buf, "The value is too large");
    else
	snprintf(buf, BUFSIZE, "The value is %" PRIdFAST16, val);
    // ...
}
