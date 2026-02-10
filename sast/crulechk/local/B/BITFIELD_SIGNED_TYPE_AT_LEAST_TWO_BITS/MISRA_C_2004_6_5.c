// @checker BITFIELD_SIGNED_TYPE_AT_LEAST_TWO_BITS

typedef struct foo_tag{
	signed int a:1; // @violation BITFIELD_SIGNED_TYPE_AT_LEAST_TWO_BITS
	signed int b:2;
}foo_struct;

void func()
{
	int a = 0;
}
