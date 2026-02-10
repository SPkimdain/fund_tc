//@checker BAD_INTEGER_EXPRESSION
enum Section : unsigned char {
     START = 'S',
     MID = 'M',
     END = 'E',
};

struct test {
	unsigned int id;
};

void BINTEXPR_001_function() {
	Section s = Section::START;
	struct test tt;
	
	if (s == tt.id ) //@violation BAD_INTEGER_EXPRESSION
	{
		return;
	}
}
