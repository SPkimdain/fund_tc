//@checker ASSEMBLER_INST_USE_ASM_DECLARATION

void delay_b(void)
{
  #pragma asm //@violation ASSEMBLER_INST_USE_ASM_DECLARATION
    "NOP"
  #pragma endasm
  ;
}
