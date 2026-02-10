//@checker ENCAPSULATE_ASSEMBLER

#define ASM_MACRO __asm out dx, al

void ENCAPASM_001_function1a() //@violation ENCAPSULATE_ASSEMBLER
{ 
	__asm mov al, 2 //@b-violation ENCAPSULATE_ASSEMBLER
	__asm mov dx, 0xD007 //@b-violation ENCAPSULATE_ASSEMBLER

	int x = 0;
	
	__asm mov ax, 0x0020 //@b-violation ENCAPSULATE_ASSEMBLER
}

void ENCAPASM_001_function2a()
{
	__asm mov al, 2
	
	__asm
	{
		mov al, 2
		mov dx, 0XD007
		out dx, al
	}
}

void ENCAPASM_001_function3a()
{
	ASM_MACRO
	int x = 0;
	
}
