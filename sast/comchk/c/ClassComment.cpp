#include <iostream>

using namespace std;

/**
 * 파일명 Main
 * @author 김지환
 * @version 1.0
 * @bad comment
 * @since 2021-01-19
 */
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