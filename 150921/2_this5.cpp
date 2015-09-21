//2. this4
//Thread�� Encapsulation

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//������Ȳ.
//Thread�� ��üȭ ��Ű��, �� ��ü�� ����ڰ� ��ӹ޾Ƽ� ���뼺�� �����ϵ��� ���α׷��� �ۼ��ϰ� �;���.
//������ window�� thread ���� �Լ��� CreateThread �Լ����� DWORD __stdcall (void*) ������ �Լ������͸� ���ڷ� �� �� �ִ�.
//Thread class�� ����Լ��� CreateThread�� �Լ������� ���ڷ� �Ѱ��ִ� ���, this ������ ������ �����.
//Thread class�� static �Լ��� CreateThread�� �Լ������� ���ڷ� �Ѱ��ִ� ���, this�� ���� ������ �Ѱ������ ������
//�� ��� ����ڰ� Thread class�� �̿��� �� ���� �ȴ�.
//�� ������ �ذ��� ����.

class Thread{
public:
	void create(){
		CreateThread(0, 0, foo, this, 0, 0);		//�ϴ� this�� ���� static�Լ� foo�� ������ �Լ��� �ѱ��.
													//CreateThread�� 4��° ���ڿ� this�� �Ѱ��ش�. �̴� foo �Լ��� void*�� �Ѱ�����.
	}

	static DWORD __stdcall foo(void* temp){			//�Ѱܹ��� this�����͸� Thread�� casting�Ѵ�. �� �� ����Լ��� foo�Լ��� ȣ���Ѵ�.
		Thread* self = static_cast<Thread*>(temp);	
		self->foo();								//�ٽ� �����Լ��� ȣ���Ѵ�. �� foo(this)�� �Ǿ�� �Ѵ�.
		return 0;
	}
	
	virtual void foo(){
		cout << "Thread" << endl;
	}
};

class MyThread : public Thread{
public:
	virtual void foo(){					//�� �Լ��� �������̵� �ǰ� Thread���ο��� ����Ǿ�� �Ѵ�.
		cout << "MyThread" << endl;
	}
};

int main(){
	Thread* t = new MyThread;
	t->create();
	
	_getch();
	return 0;
}

//���.
//Thread�� ��üȭ ��Ű�� ���� static ����Լ��� ����� CreateThread�� ���ڷ� �־���.
//����� ���� �������̵��� �����ϵ��� �ؾ��Ѵ�. ������ static���� this�� ���� �� ����.
//�׷��Ƿ� void*�� ���� this�� �Ѱܹް� �װ��� casting �Ͽ� �ٽ� virtual ��� �Լ��� ȣ���Ѵ�.
//��ü�� Thread�� �����Ͽ���.
//����.
//������ �������� ����
//���뼺 ����