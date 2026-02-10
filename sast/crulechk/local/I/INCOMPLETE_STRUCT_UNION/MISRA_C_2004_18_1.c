// @checker INCOMPLETE_STRUCT_UNION

struct A
{
	int a_var;
};

struct C // @violation INCOMPLETE_STRUCT_UNION
{
	struct A a_var;
	struct B* b_var; //@b-violation INCOMPLETE_STRUCT_UNION
};

void main()
{

}
