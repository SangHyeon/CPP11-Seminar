//2. this1
#include <iostream>
using namespace std;

//class의 멤버함수에 대해 생각해 보자.
//class의 멤버함수는 class의 멤버변수에 접근할 수 있다. 어떻게?


class Point{
	int x, y;
public:
	void set(int a, int b){
		//사실 여기에는 this라는 포인터가 생략 되어있다.
		x = a;
		y = b;
	}

	//그래서 사실 위 함수는 아래와 같이 생겼다.
	//void set(Point* const this, int a, int b){
	//	this->x = a;
	//	this->y = b;
	//}

	//그럼 static 함수는 어떨까??
	//static함수는 전역함수와 같다. this 인자가 함수 인자로 붙지 않는다.
	static void foo(int a){		// void foo( int a )

		x = a;		// this->x = a 가 되야 하는데 this가 없다.
	}				// 그래서 static 멤버에서는 멤버 변수에 접근이 불가능하다.

};




int main(){
	Point::foo(10); // static 멤버함수는 객체없이 호출가능

	Point p1, p2;
	p1.set(10, 20); // 이 순간의 원리를 생각해 봅시다..
}					// set(&p1, 10, 20) 으로 변경됩니다.


//결론.
// 1. 멤버 함수의 호출 원리
//    객체가 함수의 1번째 인자(this)로 추가된다. - this call
// 2. static 멤버 함수는 this 가 추가되지 않는다.!!







