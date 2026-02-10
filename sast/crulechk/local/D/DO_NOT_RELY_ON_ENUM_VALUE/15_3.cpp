//@checker DO_NOT_RELY_ON_ENUM_VALUE
enum Colors { RED = 0xA, GREEN, BLUE };
void function() {
	Colors color = GREEN;
	if(color == 11) { //@violation DO_NOT_RELY_ON_ENUM_VALUE
	}
} 

void function2() {
	Colors color = GREEN;
	int x = 0;
	switch(color) {
	case 10: //@violation DO_NOT_RELY_ON_ENUM_VALUE
		x++;
		break;
	case 11: //@violation DO_NOT_RELY_ON_ENUM_VALUE
		x += 2;
		break;
	case 12: //@violation DO_NOT_RELY_ON_ENUM_VALUE
		x += 3;
		break;
	case 20: //@violation DO_NOT_RELY_ON_ENUM_VALUE
		x--;
		break;
	}
}
