//2. this2
#include <iostream>
using namespace std;

//함수포인터와 멤버함수 포인터에 대해 생각해보자.

class Dialog{
public:
	void goo() { cout << "class goo" << endl; }
};

void foo(){
	cout << "function foo" << endl;
}

int main(){
	void(*f)();		//함수포인터 f 선언
	f = &foo;		//f에 foo의 주소를 넣는다.
	f();			//f를 실행

	//void(*g)() = &Dialog::goo;	//될까요?
									//class의 멤버함수는 인자로 this를 받기 때문에 불가능
									//그러므로 c++은 멤버함수 포인터를 위한 새로운 문법을 제공한다.
	void(Dialog::*g)() = &Dialog::goo;	//ok.. 멤버함수포인터 정의 외워두세요.
	//g();							//될까요?
									//error this를 인자로 주어야 한다. 즉 인스턴스 없이 멤버함수만 호출하는 것은 불가능하다.

	Dialog dlg;
	//dlg.g();						//dlg.g() 는 g(&dlg)로 변경된다.
									//그리고 g 멤버함수포인터에는 goo가 들어있으므로 goo(&dlg)가 된다.
									//하지만 이렇게 할 경우 compiler는 Dialog class 내부에서 g라는 함수를 찾게 된다.
									//왜냐하면 저 형태가 일반 멤버함수 호출과 똑같이 생겼기 때문이다.
									//그러므로 c++은 멤버함수 포인터 사용을 위한 새로운 문법을 제공한다.

	//dlg.*g();						//(.*연산자) 하지만 이 경우 ()연산자가 우선순위가 높다.
	(dlg.*g)();						//그러므로 다음과 같이 사용한다.	(.*연산자) 멤버함수포인터의 사용법 외워두세요.

	Dialog* pdlg = &dlg;			//pointer로 인스턴스가 정의된 경우
	(pdlg->*g)();					//(->*연산자) 멤버함수포인터의 사용법 외워두세요.
	return 0;
}

//결론. 멤버함수 포인터를 위한 3가지 연산자가 추가되었다.
//멤버함수 포인터 선언						void(Dialog::*g)();
//멤버함수 포인터 사용						(dlg.*g)();		(Dialog dlg가 미리 선언되어 있어야 한다.)
//포인터 객체를 통한 멤버함수 포인터 사용	(pdlg->*g)()	(Dialog* pdlg가 미리 선언되어 있어야 한다.)