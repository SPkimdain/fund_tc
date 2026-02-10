//@checker UNSPECIFY_BUFFER_LENGTH_CIN
#include <iostream>

using namespace std;

#define CHAR_BUFFER_SIZE 10

void bad(){
	char charBuffer[CHAR_BUFFER_SIZE];
	cin >> charBuffer;	//@violation UNSPECIFY_BUFFER_LENGTH_CIN
}

void good(){
	char charBuffer[CHAR_BUFFER_SIZE];
	cin.width(CHAR_BUFFER_SIZE);
	cin >> charBuffer;
}
