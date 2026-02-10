//@checker USE_POINTER_ARITHMETIC_ON_FIELD

struct numbers {
	short num_a, num_b, num_c;
};
 
int sum_numbers(struct numbers *numb){
	int total = 0;
	short *numb_ptr;
	short* numb_ptr2 = &numb->num_a;

	for(numb_ptr = &numb->num_a; 
		numb_ptr <= &numb->num_c;
		numb_ptr++) { //@violation USE_POINTER_ARITHMETIC_ON_FIELD
		total += *(numb_ptr);
	}

	numb_ptr2 = numb_ptr2 + 1; //@violation USE_POINTER_ARITHMETIC_ON_FIELD

	return total;
}
 
int main(void) {
	struct numbers my_numbers = { 1, 2, 3 };
	
	sum_numbers(&my_numbers);
	
	return 0;
}
