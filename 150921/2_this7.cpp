#include <iostream>
using namespace std;

// NULL ��ü�� �Լ� ȣ�⹮��..
class Test{
	int data;
public:
	void f1() { cout << "f1" << endl; }					//this�� ������� �����Ƿ� ��� ����.
	int  f2() { cout << "f2" << endl; return 0; }
	int  f3() { cout << "f3" << endl; return data; }	// this->data

	virtual void f4() {}
};

int main(){
	Test* p = 0;	// �޸� �Ҵ翡 ���� �ؼ� 0�� ���Դٰ� �����մϴ�.
	//p->f1();		// ��� �ɱ�� ?? �������� ���� ������ ������  f1(p)
					// f1(p), f1(0)
	//p->f2();		// ok
	//p->f3();		//?

	//p->call_f3();

	p->f4();		// �ɱ�� ? 0 ������ �����Լ� ���̺��� �ִٰ� ����
					// p->vptr->vtable->(�����Լ� ã�Ƽ� ����)  ������ this�� null�̹Ƿ� ������� (vptr, vtable)�� ������ �Ұ���
					// �ϰ� �ȴ�.!! ����ð� error
}

//���.
//�� ��ü�� null�̾ ����Լ�����this�� �����ϱ� �������� ������ ���� �ʴ´�.
//�����Լ��� ��� �����Լ� ���̺��� �����ϱ� ���� ����(vptr)�� �����ϴµ�, ������ ���� �ʾ����Ƿ� error

