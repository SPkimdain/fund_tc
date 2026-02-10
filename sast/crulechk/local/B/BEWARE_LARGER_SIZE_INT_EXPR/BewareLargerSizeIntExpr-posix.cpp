//@checker BEWARE_LARGER_SIZE_INT_EXPR
 
enum : short { BLOCK_HEADER_SIZE = 16 };
 
void *AllocateBlock(short length) {
  struct memBlock *mBlock;
 
  if (length + BLOCK_HEADER_SIZE > (unsigned long long)0xffffffff)	//@violation BEWARE_LARGER_SIZE_INT_EXPR
  {
    return 0;
  }

  if ((unsigned long long)length + BLOCK_HEADER_SIZE > 0xffffffff) // ok
  {	
    return 0;
  }

  
  if (!mBlock) { return 0; }
  /* Fill in block header and return data portion */
 
  return mBlock;
}
