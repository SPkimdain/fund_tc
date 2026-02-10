// @checker UNSUITABLE_BITFIELD_TYPE


typedef struct foo_tag{
	signed int a:1;
	signed long b:2;	// @violation UNSUITABLE_BITFIELD_TYPE
	unsigned short c:3;	// @violation UNSUITABLE_BITFIELD_TYPE
}foo_struct;

void func()
{
	int a = 0;
}
