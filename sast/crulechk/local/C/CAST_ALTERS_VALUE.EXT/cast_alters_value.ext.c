//@checker CAST_ALTERS_VALUE.EXT
void cast_alters_value(){
	char c = 'a';
	
	c = (char)-100;	
	c = (char)127U;
	c = (char)777U; //@violation CAST_ALTERS_VALUE.EXT
	c = (char)-200;	//@violation CAST_ALTERS_VALUE.EXT
	
}