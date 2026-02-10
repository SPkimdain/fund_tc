//@checker DO_NOT_WRITE_CONFUSED_CHARACTER

//식별자 목록 : 변수, 구조체명, 클래스명, ENUM명, 함수명, typedef 명

class lO0 // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
{
public:
	void l1Member(); // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
	int l1Attribute; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
};

typedef int O0typedef; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER

enum l1enum // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
{
	apple,
	l1enumAttr // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
};

void l1O0Func() // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
{
	int x = 0;
}

typedef struct _O0StructName // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
{
	float O0struct; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
	float o0struct2; 
} O0StructName; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER

struct _struct_tag_l1 // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
{
	int l1struct; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
	long l1struct2; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
} strcutVal;

int main() 
{

	int l1; // @violation DO_NOT_WRITE_CONFUSED_CHARACTER
}
