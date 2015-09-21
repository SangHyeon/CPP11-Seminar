//1. static1
//static을 사용하는 이유는?
//전역변수를 사용하는 이유는?
//starcraft Unit의 개체 수를 관리하는 class를 구현해보자.


#include <iostream>
using namespace std;


//여러 객체의 수를 count하기 위한 "공유 변수"
int cnt;
class Unit{
public:
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
};

//모두 Unit의 생성자를 호출하기 때문에 cnt는 증가한다.
class Zealot : public Unit{};

class Medic : public Unit{};


void test(){		//함수 내에서 객체가 생성되고 함수가 끝날 때 객체가 소멸한다.
	Zealot z1, z2;
	Medic m1, m2;

	cout << cnt << endl;
}

int main(){
	test();
	cout << cnt << endl;
	return 0;
}

//결론. 전역변수는 "공유되는 변수" 라는 점에서 매우 중요하다.