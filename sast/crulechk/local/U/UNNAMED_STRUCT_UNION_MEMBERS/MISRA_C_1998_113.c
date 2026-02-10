// @checker UNNAMED_STRUCT_UNION_MEMBERS

static struct s
{
	signed int p_a : 4; 
	unsigned int p_b : 1; 
    signed int : 8;	//@violation	UNNAMED_STRUCT_UNION_MEMBERS
	unsigned int p_c : 4; 
	struct {	//@violation	UNNAMED_STRUCT_UNION_MEMBERS
		int foo;
		int bar;
	};
} st;

union{
	unsigned int a : 4;
	signed int : 5	//@violation UNNAMED_STRUCT_UNION_MEMBERS

}variant;

void func(int foo)	
{
	st.p_a = 0x1;
}
