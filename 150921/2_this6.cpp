//2. this6
//this와 virtual
//virtual을 쓰는 이유 => Polymorphism

#include <iostream>
using namespace std;

//class 가 runtime에 가상함수를 찾을 수 있는 이유는 무엇일까?
//그것은 바로 가상함수테이블(vtable)이 있기 때문이다.

class A{
	 void f(){}
};
class B : public A{
	 virtual void f(){}
};
class C : public A{
	void f(){}
};

class Parent{
public:
	virtual void print(){ cout << "parent" << endl; }
};
class Child : public Parent{
public:
	virtual void print(){ cout << "child" << endl; }
};

int main(){
	//이 크기의 차이는 가상함수 테이블의 존재여부 때문에 생긴다.
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	
	Parent* p = new Child;

	//그러므로 사실 아래 문장은 다음과 같다.
	//p->vptr->vtable->(Parent와 Child중 적절한 print);
	p->print();

	return 0;
}

//결론.
//가상함수를 만들기 위해서는 가상함수 테이블을 만들어야 한다.