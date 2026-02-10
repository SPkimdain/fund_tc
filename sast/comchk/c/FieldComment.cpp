#include <iostream>

using namespace std;

class People {
private:
	// int 타입 변수: 나이
	int age;
	/* string 타입 변수: 이름 */
	string name;
	/* string 타입 변수: 
	 * 주소 
	 */
	string address;

public:
	string getName() {
        return this->name;
    }
    void setName(string _name) {
        this->name = _name;
    }
};