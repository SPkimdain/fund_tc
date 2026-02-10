//@checker BAD_CALL.INVALID_BLOCK_SIZE.ALLOC
extern void* realloc (void* ptr, int size);
extern void* malloc (int size);

int bad_call_invalid_block_size_alloc()
{
	long *ptd;
	ptd = (long *) realloc(ptd, 11);//@violation BAD_CALL.INVALID_BLOCK_SIZE.ALLOC
	ptd = (long *) malloc(3);	//@violation	BAD_CALL.INVALID_BLOCK_SIZE.ALLOC
	ptd = (long *) malloc(11);	//@violation BAD_CALL.INVALID_BLOCK_SIZE.ALLOC
	ptd = (long *) malloc(13);	//@violation BAD_CALL.INVALID_BLOCK_SIZE.ALLOC
	ptd = (long *) malloc(12);

	return 0;
}