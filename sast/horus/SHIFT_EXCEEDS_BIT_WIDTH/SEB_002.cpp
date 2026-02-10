/* a simple shift exceed bit width example(unsigned char) */

void SEB_002_function(unsigned char u8a, unsigned char u16a){
	int shift7 = 7;
	int shift8 = 8;
	int shift9 = 9;
	unsigned char c1 = (unsigned char)(u8a << shift7);
	unsigned char c2 = (unsigned char)(u8a << shift8); //@violation SHIFT_EXCEEDS_BIT_WIDTH
	unsigned short s1 = (unsigned short)((unsigned short)u8a << shift9);
}
