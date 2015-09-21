//2. this4
//Win32 thread를 c++ class로 Encapsulate 함으로써
//재사용성을 증가시킨다.
//thread의 복잡한 생성과정을 감춘다.


#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

class Thread{
public:
	void create(){									//thread를 생성하는 create 함수를 구현
		CreateThread(0, 0, foo, 0, 0, 0);
	}

	
	/*virtual DWORD __stdcall foo(void* temp){		//thread에서 수행할 함수, 하지만 this때문에 넘겨질 수 없다.
		cout << "Thread" << endl;						
		return 0;
	}*/

													//그렇다면 this가 없는 static 함수를 이용해보자.
	static DWORD __stdcall foo(void* temp){			//하지만 static 함수의 경우 virtual을 통해 사용자가 Thread를 이용하도록 할 수가 없다.
		cout << "Thread" << endl;
		return 0;
	}
};

//사용자가 Thread class를 상속하여 원하는 작업을 하는 Thread를 만든다.
class MyThread : public Thread{
public:
	virtual DWORD __stdcall foo(void* temp){		//이 함수가 오버라이딩 되고 Thread내부에서 실행되어야 한다.
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