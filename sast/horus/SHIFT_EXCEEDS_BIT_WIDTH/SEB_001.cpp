/* a simple shift exceed bit width example(unsigned char) */

void SEB_001_function(unsigned char u8a, unsigned char u16a){
	unsigned char c1 = (unsigned char)(u8a << 7);
	unsigned char c2 = (unsigned char)(u8a << 8); //@violation SHIFT_EXCEEDS_BIT_WIDTH
	unsigned short s1 = (unsigned short)((unsigned short)u8a << 9);
}
