//@checker ENCAPSULATE_ASSEMBLER

#define ASM_MACRO __asm__ ("mov %eax, 16");

void ENCAPASM_001_function1b() //@violation ENCAPSULATE_ASSEMBLER
{ 
  int x = 0;
	__asm__ ("mov %eax, 0"); //@b-violation ENCAPSULATE_ASSEMBLER
	__asm__ ("mov %ebx, x"); //@b-violation ENCAPSULATE_ASSEMBLER
}

void ENCAPASM_001_function2b()
{
	__asm__ ("mov %eax, 4");
	
	__asm__
	(
		"mov %eax, 8"
		);
}

void ENCAPASM_001_function3b()
{
	ASM_MACRO
	int x = 0;
	
}
