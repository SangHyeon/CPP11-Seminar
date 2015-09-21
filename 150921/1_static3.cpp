//1. static3
//변수의 영향범위를 생각해보고 접근권한을 지정하자.


#include <iostream>
using namespace std;

//문제상황.
//외부에서 Unit의 cnt변수 값을 바꿀 수가 있다.
//이러한 가능성이 있어서는 안된다.


//해결.
//접근 권한을 주자. (Encapsulation)
class Unit{
private:
	static int cnt;			//Unit class에서 유효한 전역변수 cnt를 정의함
public:
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
	static const int& get_cnt() { return cnt; }		//외부에서 cnt의 값을 꺼내고 싶을 때
};
int Unit::cnt = 0;

class Zealot : public Unit{};
class Medic : public Unit{};

void test(){
	Zealot z1, z2;
	Medic m1, m2;

	cout << Unit::get_cnt() << endl;
}

int main(){
	test();
	cout << Unit::get_cnt() << endl;
	return 0;
}

//결론. 접근권한을 줌으로써 완벽한 객체화(Encapsulation)
//외부에서 접근되는 가능성을 남기지 않는다.