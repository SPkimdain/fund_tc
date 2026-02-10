//@checker BAD_MACRO.DANGEROUS_USAGE
#define pow(a) ((a)*(a)) //@violation BAD_MACRO.DANGEROUS_USAGE

void BMACDU_001_function(){
   int b = 3;
   int c = 24 * pow(b);
}

