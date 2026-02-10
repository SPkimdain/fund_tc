//@checker DO_NOT_OPERATE_ENUMERATOR

enum Color { COLOR_0, COLOR_1, COLOR_2, COLOR_3 } color;

void func() {
	int a = 0;
	
	a = COLOR_0 + COLOR_1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = COLOR_0 + 1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = COLOR_0 - 1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = COLOR_0 * 1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = COLOR_1 / 1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	
	a = 1 + COLOR_0;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = 1 - COLOR_0;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = 1 * COLOR_0;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a = 1 / COLOR_1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	
	a -= COLOR_1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a *= COLOR_1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	a /= COLOR_1;	//@violation DO_NOT_OPERATE_ENUMERATOR
	
	if((COLOR_0 + COLOR_1) == 1) {	//@violation DO_NOT_OPERATE_ENUMERATOR
		
	}
	
}