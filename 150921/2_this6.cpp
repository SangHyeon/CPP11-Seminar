//2. this6
//this�� virtual
//virtual�� ���� ���� => Polymorphism

#include <iostream>
using namespace std;

//class �� runtime�� �����Լ��� ã�� �� �ִ� ������ �����ϱ�?
//�װ��� �ٷ� �����Լ����̺�(vtable)�� �ֱ� �����̴�.

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
	//�� ũ���� ���̴� �����Լ� ���̺��� ���翩�� ������ �����.
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	
	Parent* p = new Child;

	//�׷��Ƿ� ��� �Ʒ� ������ ������ ����.
	//p->vptr->vtable->(Parent�� Child�� ������ print);
	p->print();

	return 0;
}

//���.
//�����Լ��� ����� ���ؼ��� �����Լ� ���̺��� ������ �Ѵ�.