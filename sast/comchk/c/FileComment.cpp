/**
 * FileComment1.cpp 파일 주석의 형식 TC
 */
#include <iostream>

using namespace std;

class People {
private:
    int age;
	string name;
	string address;

public:
	string getName() {
        return this->name;
    }
    void setName(string _name) {
        this->name = _name;
    }
};