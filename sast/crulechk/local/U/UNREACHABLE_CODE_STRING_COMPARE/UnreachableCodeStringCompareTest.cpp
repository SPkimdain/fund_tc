//@checker UNREACHABLE_CODE_STRING_COMPARE

typedef long size_t;
extern int strcmp ( const char * str1, const char * str2 );
extern int strncmp ( const char * str1, const char * str2, size_t num );

struct Field
{
	char* x;
	char arr[10];
	typedef struct _Nested
	{
		char* x;
		char arr[10];
	} Nested;
	Nested n;
};

void compare(char* str, Field fStr, bool flag, int k)
{
	int x = 0;
  
	/* Case 1 : 문제 없는 코드 */
	if(str[0] == 'X')
	{
		x++;
	}
	else if(str[0] == 'Y')
	{
		x++;
		/* if-elseif 중첩 검사용 코드. */
		if(flag == true)
		{
			x++;
			if(k < 20)
			{
				x++;
			}
			else if(k < 30)
			{
				x++;
			}
			else if(k < 40)
			{
				x++;
			}
			else
			{
				x++;
			}
		}
		else if(flag == false)
		{
			x++;
			if(k == 10)
			{
				x++;
			}
			else if(k == 5)
			{
				x++;
			}
		}
		else if(k < 10)
		{
			x++;
		}
	}

	if(strcmp(str, "TES") == 0)
	{
		x++;
	}
	else if(strcmp(str, "TEST") == 0) /* strcmp이므로 전부 같아야 한다. 따라서 문제 없음. */
	{
		x++;
	}

	if(fStr.n.arr[2] == 'X')
	{
		x++;
	}
	else if(fStr.n.arr[2] == 'Y')
	{
		x++;
	}
	else if(fStr.n.arr[2] == 'Z')
	{
		x++;
	}

	if(strcmp(fStr.n.arr, "TES") == 0)
	{
		x++;
	}
	else if(strcmp(fStr.n.arr, "TEST") == 0)
	{
		x++;
	}
	else if(strncmp(fStr.n.arr, "TEST2", 5) == 0)
	{
		x++;
	}

	/* Case 2. if-elseif 체인에 Unreachable Code가 존재. */
	if(str[0] == 'X') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(str, "XTEST") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(str, "XT", 2) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	if(strcmp(fStr.x, "TEST") == 0)
	{
		x++;
	}
	else if(strncmp(fStr.x, "TT", 2) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(fStr.x, "TTT") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	if(str[0] == 'X') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(str, "X", 1) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}




	/* Case 3. Offset이 존재. */
	if(strncmp(str + 2, "TES", 3) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(str + 2, "TEST") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* 2번째 글자가 X인 경우 위에서 전부 실행되며, else-if절에서 첫번째 단어부터 비교시 위에 포함되므로
	 * Unreachable code이다.
	 */
	if(fStr.n.arr[1] == 'X') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(fStr.n.arr, "TX", 2) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strcmp(fStr.n.arr, "KXT") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* 복잡한 offset 구성을 하여 정확한 분석을 하는지 테스트. */
	if(strncmp(fStr.n.arr + 2, "CD", 2) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* 두번째 문자부터 시작하는 CD로 인해, 아래쪽의 BCDT는 Unreachable Code이다. */
	else if(strncmp(fStr.n.arr + 1, "BCDT", 3) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* 두번째 문자부터 시작하는 CD로 인해, 아래쪽의 ATCDX는 Unreachable Code이다. */
	else if(strncmp(fStr.n.arr, "ATCDX", 5) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	/* Case 4. 중첩 if문이 존재. */
	if(fStr.n.arr[0] == 'A') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		if(strcmp(fStr.n.arr + 1, "BCD") == 0)
		{
			x++;
		}
		else if(fStr.n.arr[0] == 'B') //@violation UNREACHABLE_CODE_STRING_COMPARE
		{
			x++;
		}
	}

	/* offset + 2에서 C와 D는 서로 겹칠 수 없다. */
	if(strncmp(str, "ABC", 3) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		if(strncmp(str + 1, "BD", 2) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
		{
			x++;
		}
	}
	
	/* Case 5. 복합 조건절. 이때 다른 조건들에 의해 Unreachable Code가 아니더라도 
	 * 잠재적으로 Unreachable Code가 될수 있는 위험성이 있다고 판단하고 알람을 내도록 함.
	 */
	if(flag == false && strncmp(str, "ABC", 3) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(flag == false && strcmp(str, "ABCDE") == 0) //@non-violation UNREACHABLE_CODE_STRING_COMPARE //deprecated
	{
		x++;
	}

	/* Case 6. 부정수식 비교 - 해당 부분은 보류 */
	if(strcmp(str, "123") != 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* 반드시 123 */
	else if(strcmp(str, "123") != 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}

	if(strncmp(str, "ABC", 3 ) != 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		/* 문제 없음. 세번째 글자가 다르므로. */
		if(strncmp(str, "ABD", 3) == 0)
		{
			x++;
		} /* 모순절. */
		else if(strncmp(str, "ABC", 3) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
		{
			x++;
		}
	}
	else if(strncmp(str, "ABCD", 4) != 0) /* Unreachable Code? or not? */
	{
		x++;
	}

	/* Case 7. 같은 if-elseif 체인절에 서로 다른 문자열 비교 수식들이 혼재된 경우 비교 */
	if(str[1] == 'B') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	else if(strncmp(fStr.arr + 2, "XX", 2) == 0) //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* str[1] == 'B' 절에 의해 알람. */
	else if(strcmp(str, "XBT") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* strncmp(fStr.arr + 2, "XX") == 0 절에 의해 알람. */
	else if(strncmp(fStr.arr, "ABXXTT", 5) == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
	
	if(str[0] == 'A') //@b-violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	} /* 비교 문장이 두개 있지만, 뒤의 str 문 검사에 의해 알람. */
	else if(strcmp(fStr.arr, "XXX") == 0 || strcmp(str, "ABC") == 0) //@violation UNREACHABLE_CODE_STRING_COMPARE
	{
		x++;
	}
  
  /* Case 8. Double-check, false alarm */
  if(strcmp(fStr.arr, "11") == 0 || strcmp(fStr.arr, "22") == 0 || strcmp(fStr.arr, "33") == 0) { //It is false alarm source.
    if(strcmp(fStr.arr, "11") == 0) { //It's ok.
      x++;
    } else if(strcmp(fStr.arr, "22") == 0) { //It's ok. 
      x++;
    } else if(strcmp(fStr.arr, "33") == 0) { //It's ok. 
      x++;
    }
  }
}


int main()
{

	return 0;
}
