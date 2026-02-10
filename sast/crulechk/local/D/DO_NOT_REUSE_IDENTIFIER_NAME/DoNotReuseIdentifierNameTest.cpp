//@checker DO_NOT_REUSE_IDENTIFIER_NAME

// 1. 함수명, 라벨명, enum 상수명, 변수명, 함수 인자명, 태그명, 필드명 == 함수명, 라벨명, enum 상수명, 변수명, 함수 인자명, 태그명, 필드명

extern int globalExternVar;

int globalVar2;

void DNRIN_externTestFunct();

void DNRIN_externTestFunct() { //It's ok.
  int globalExternVar = 120; //It's ok.
  int etf = 10;
}

void DNRIN_func() //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	char DNRIN_variableName = 1; //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME

	union DNRIN_tagName //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x;
		int y;
		int DNRIN_fieldName; //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	};
}

//필드명 == 함수명
void DNRIN_fieldName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	return;
}

//태그명 == 함수명
void DNRIN_tagName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//변수 == 변수
	int DNRIN_variableName = 5; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
//필드명 == 라벨명
DNRIN_fieldName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	return;
}

//변수 == 함수
int DNRIN_variableName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
//변수 == 라벨
DNRIN_variableName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	int xyz = 10;
//태그 == 라벨
DNRIN_tagName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	return xyz;
}

void DNRIN_func2()
{
//함수 == 라벨
DNRIN_func: //@violation DO_NOT_REUSE_IDENTIFIER_NAME

DNRIN_labelName: //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	struct DNRIN_StructName //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x2;
		int y2;
	} str;

	enum EnumList
	{
		DNRIN_first, //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
		//함수 == enum 상수
		DNRIN_func, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		enumTest, //@y-violation DO_NOT_REUSE_IDENTIFIER_NAME
		//변수 == enum상수
		DNRIN_variableName, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//태그 == enum상수
		DNRIN_tagName, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//필드 = enum상수
		DNRIN_fieldName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};

}

//태그명 == 함수명
void DNRIN_StructName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//필드명 == 변수명
	char DNRIN_fieldName ; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//태그명 == 변수명
	int DNRIN_tagName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
//태그명 == 라벨명
DNRIN_StructName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	return;
}

//enum상수 == 함수
void DNRIN_first() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//필드명 == 태그명
	union DNRIN_fieldName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int xxx;
		int yyy;
	};

	//태그명 == 태그명
	struct DNRIN_tagName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int k;
		char y3;
	};
	//변수 == 태그
	struct DNRIN_variableName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int xx1;
		int yy1;
	};

	struct StructTest3
	{
		int xxx2;
		//변수 == 필드
		char DNRIN_variableName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};
	return;
}

//라벨 == 함수
void DNRIN_labelName() //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//enum상수 == 변수
	int DNRIN_first; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//enum상수 == 라벨
DNRIN_first: //@violation DO_NOT_REUSE_IDENTIFIER_NAME

	return;
}

//변수 == 함수인자명
void DNRIN_func3( short DNRIN_variableName ) //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//변수 == 태그명	
	//{
	int x4;
	int y4;
	//태그명 == 필드명
	short DNRIN_tagName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//필드명 == 필드명
	short DNRIN_fieldName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//} inst3;
	//함수 == 변수
	int DNRIN_func = 10; //@violation DO_NOT_REUSE_IDENTIFIER_NAME

	struct StructTest2
	{
		int x5;
		char DNRIN_variableName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	} inst4;
}

//함수 == 함수 인자명
void DNRIN_func4( char DNRIN_func ) //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	//enum상수 == 태그명
	struct DNRIN_first //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x6;
		int y6;
	} inst;

	union UnionTest
	{
		char xx7;
		//enum상수 == 필드명
		char DNRIN_first; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	} inst2;
	//라벨 == 변수
	int DNRIN_labelName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
}

void DNRIN_func5()
{
	//enum상수 == 변수
	int DNRIN_first; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	//함수 == 태그명
	struct DNRIN_func //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	{
		int x8;
		int y8;
	};

	union StructTest
	{
		int x9;
		//함수 == 필드명
		char DNRIN_func; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//라벨 == 필드명
		short DNRIN_labelName; //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};
}

//enum상수 == 함수 인자
void DNRIN_func6( int DNRIN_first ) //@violation DO_NOT_REUSE_IDENTIFIER_NAME
{
	return;
}


int DNRIN()
{
//라벨 == 라벨
DNRIN_labelName: //@violation DO_NOT_REUSE_IDENTIFIER_NAME

	enum EnumList2
	{
		//enum상수 = enum상수
		DNRIN_first, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		second,
		//enum상수 == tag명
		enumTest, //@violation DO_NOT_REUSE_IDENTIFIER_NAME
		//라벨 == enum상수
		DNRIN_labelName //@violation DO_NOT_REUSE_IDENTIFIER_NAME
	};


	return 1;
}
