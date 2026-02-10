#include <iostream>

using namespace std;

class People {
private:
    int age;
	string name;
	string address;

public:
	/**
     * name 값을 반환하는 함수
     *
     * @return 반환값
     * @since 2021-01-19
     */
	string getName() {
        return this->name;
    }
	/**
     * name 값을 설정하는 함수
     *
     * @param name1 String 타입
     * @since 2021-01-19
     */
    void setName(string _name) {
        this->name = _name;
    }
};