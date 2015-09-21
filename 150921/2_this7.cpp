#include <iostream>
using namespace std;

// NULL 객체의 함수 호출문제..
class Test{
	int data;
public:
	void f1() { cout << "f1" << endl; }					//this를 사용하지 않으므로 상관 없다.
	int  f2() { cout << "f2" << endl; return 0; }
	int  f3() { cout << "f3" << endl; return data; }	// this->data

	virtual void f4() {}
};

int main(){
	Test* p = 0;	// 메모리 할당에 실패 해서 0이 나왔다고 가정합니다.
	//p->f1();		// 어떻게 될까요 ?? 실행하지 말고 생각해 보세요  f1(p)
					// f1(p), f1(0)
	//p->f2();		// ok
	//p->f3();		//?

	//p->call_f3();

	p->f4();		// 될까요 ? 0 번지에 가상함수 테이블이 있다고 생각
					// p->vptr->vtable->(가상함수 찾아서 실행)  하지만 this가 null이므로 멤버변수 (vptr, vtable)에 접근이 불가능
					// 하게 된다.!! 실행시간 error
}

//결론.
//즉 객체가 null이어도 멤버함수에서this에 접근하기 전까지는 에러가 뜨지 않는다.
//가상함수의 경우 가상함수 테이블을 참조하기 위한 변수(vptr)에 접근하는데, 생성이 되지 않았으므로 error

