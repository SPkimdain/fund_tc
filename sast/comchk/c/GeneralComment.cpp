#include <iostream>

using namespace std;

class People {
private:
    int age;
	string name;
	string address;

public:
	string getName() {
		/* name을 리턴하는 부분 */
        return this->name;
		/*
         * 실행 안되는 부분
         */
    }
    void setName(string _name) {
		// name값을 set하는 부분
        this->name = _name;
    }
};