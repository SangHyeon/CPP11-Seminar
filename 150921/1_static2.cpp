//1. static2
//static을 사용하는 이유는?
//전역변수의 문제점을 생각해보자.


#include <iostream>
using namespace std;

//문제상황.
//전역변수 cnt의 범위는 너무 넓다. 프로그램 전체에 걸쳐 영향을 미친다.
//이 문제는 프로그램이 소규모일 때는 심각하지 않지만, 대규모일 때는 심각해진다.

//어떠한 공유되는 변수라도 그 영향범위가 있다.
//그러면 전역변수처럼 "공유되는 변수"라는 속성을 갖으며, 지역변수처럼 영향범위를 한정시킬 수 있을까?
/*int cnt;
class Unit{
public:
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
};*/

//해결.
//그래서 static 키워드가 탄생함
class Unit{
public:
	static int cnt;				//Unit class에서 유효한 전역변수 cnt를 정의함
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
};
int Unit::cnt = 0;				//static 변수의 초기화 방법

class Zealot : public Unit{};
class Medic : public Unit{};

void test(){
	Zealot z1, z2;
	Medic m1, m2;

	cout << Unit::cnt << endl;	//static 변수에 접근
}

int main(){
	test();
	cout << Unit::cnt << endl;

	//하지만 이 경우에 대해 생각해보자.
	Unit::cnt = 7;
	//Unit이라는 class 외부에서 cnt에 접근할 필요가 있을까?
	return 0;
}
