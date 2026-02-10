//@checker USE_SUFFIX_FOR_UNSIGNED_INTEGER_LITERALS

template<typename T>
void MISRA2008_2_13_3___f(T)
{
}

template<>
void MISRA2008_2_13_3___f<unsigned int>(unsigned int)
{
}

template<>
void MISRA2008_2_13_3___f<int>(int)
{
}

void MISRA2008_2_13_3___b()
{
	unsigned int u32a = 0U;         //compliant
	MISRA2008_2_13_3___f(0x8000);   //Non-compliant  //@violation USE_SUFFIX_FOR_UNSIGNED_INTEGER_LITERALS
	u32a = u32a + 0x8000;           //Non-compliant  //@violation USE_SUFFIX_FOR_UNSIGNED_INTEGER_LITERALS
} 
