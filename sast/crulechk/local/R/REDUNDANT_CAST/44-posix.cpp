//@checker REDUNDANT_CAST

void func()
{
	int x = 10;
	int y = 20;
	x = (int)y + 1; //@violation REDUNDANT_CAST

	char z = 'x';

	/* 최종적으로 int형으로 캐스팅 되지만, 명시적으로 동일한 타입을 가지는 변수에 대해 동일한 타입으로 캐스팅 함 */
	x = (char)z; //@violation REDUNDANT_CAST

	/* 문제 없음 */
	x = (unsigned int)y - 1;

	float fx = 3.3F;
	float fy = 50.2F;

	/* 문제 없음 */
	x = (int)fx + 10;

	if((float)fx == 10.3F) //@violation REDUNDANT_CAST
	{
		x++;
	}
	
}

int main()
{
	return 0;
}
