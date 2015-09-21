//1. static5
//전역변수의 영향범위가 있다면, 범위에 맞게 static 변수로 만드는 것이 프로그램의 복잡도를 낮춘다.
//그렇다면 다음과 같은 경우는 어떠한가?

#include <iostream>
using namespace std;

//문제상황. A와 B의 수를 count하고 싶다.
//이전과 달리 상속관계가 없다.

/*
int cnt;
class A{
	A(){ cnt++; }
	~A(){ cnt++; }
};

class B{
	B(){ cnt++; }
	~B(){ cnt++; }
};
*/

//전역변수는 프로그램의 복잡도를 증가시키기 때문에 최대한 사용하지 않아야 한다.
//해결.
//이 경우 공유되는 변수를 객체로 감싼다.
//이 객체는 getInstance() 메서드로만 호출이 가능하고, 단 한번만 생성된다.
//이 객체는 cnt에 대한 getter 증가에 대한 함수를 제공
//전역변수의 naming 문제와 접근권한 문제를 해결(Singleton Pattern)
class ShareVal{
private:
	int cnt;
	static ShareVal* instance;
public:
	ShareVal():cnt(0){}
	// 오직 하나의 객체만 만들어서 리턴하는 정적 함수
	static ShareVal& getInstance(){
		if (instance == 0){
			instance = new ShareVal;
		}
		return *instance;
	}
	const int& get_cnt()const{ return cnt; }	//cnt 반환
	void increase_cnt(){ this->cnt++; }			//cnt 증가
	void decrease_cnt(){ this->cnt--; }			//cnt 감소
};
ShareVal* ShareVal::instance = 0;


class A{
public:
	A(){ ShareVal::getInstance().increase_cnt(); }	//ShareVal class의 instance를 불러서 cnt를 조작한다.
	~A(){ ShareVal::getInstance().decrease_cnt(); }
};

class B{
public:
	B(){ ShareVal::getInstance().increase_cnt(); }
	~B(){ ShareVal::getInstance().decrease_cnt(); }
};

void test(){
	A a1, a2;
	B b1, b2;

	cout << ShareVal::getInstance().get_cnt() << endl;	//ShareVal class의 instance를 불러서 cnt를 반환
}

int main(){
	test();
	cout << ShareVal::getInstance().get_cnt() << endl;
	return 0;
}

//결론. Singleton 패턴을 이용하여 서로 다른 객체 간 전역변수의 naming문제와 접근권한 문제를 해결
//하지만 Singleton객체가 너무 많으면 그 또한 프로그램의 복잡도를 증가시킨다. (Singleton을 구현할 때는 많은 고민 후에 구현하자.)