//2. this4
//Win32 thread�� c++ class�� Encapsulate �����ν�
//���뼺�� ������Ų��.
//thread�� ������ ���������� �����.


#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

class Thread{
public:
	void create(){									//thread�� �����ϴ� create �Լ��� ����
		CreateThread(0, 0, foo, 0, 0, 0);
	}

	
	/*virtual DWORD __stdcall foo(void* temp){		//thread���� ������ �Լ�, ������ this������ �Ѱ��� �� ����.
		cout << "Thread" << endl;						
		return 0;
	}*/

													//�׷��ٸ� this�� ���� static �Լ��� �̿��غ���.
	static DWORD __stdcall foo(void* temp){			//������ static �Լ��� ��� virtual�� ���� ����ڰ� Thread�� �̿��ϵ��� �� ���� ����.
		cout << "Thread" << endl;
		return 0;
	}
};

//����ڰ� Thread class�� ����Ͽ� ���ϴ� �۾��� �ϴ� Thread�� �����.
class MyThread : public Thread{
public:
	virtual DWORD __stdcall foo(void* temp){		//�� �Լ��� �������̵� �ǰ� Thread���ο��� ����Ǿ�� �Ѵ�.
		cout << "MyThread" << endl;
		return 0;
	}
};


int main(){
	Thread* t = new MyThread;
	t->create();

	_getch();
	return 0;
}