//2. this4
//Thread의 Encapsulation

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

//문제상황.
//Thread를 객체화 시키고, 그 객체를 사용자가 상속받아서 재사용성을 증가하도록 프로그램을 작성하고 싶었다.
//하지만 window의 thread 생성 함수인 CreateThread 함수에는 DWORD __stdcall (void*) 형태의 함수포인터만 인자로 들어갈 수 있다.
//Thread class의 멤버함수를 CreateThread에 함수포인터 인자로 넘겨주는 경우, this 때문에 문제가 생긴다.
//Thread class의 static 함수를 CreateThread에 함수포인터 인자로 넘겨주는 경우, this가 없기 때문에 넘겨지기는 하지만
//이 경우 사용자가 Thread class를 이용할 수 없게 된다.
//위 문제를 해결해 보자.

class Thread{
public:
	void create(){
		CreateThread(0, 0, foo, this, 0, 0);		//일단 this가 없는 static함수 foo를 실행할 함수로 넘긴다.
													//CreateThread의 4번째 인자에 this를 넘겨준다. 이는 foo 함수의 void*로 넘겨진다.
	}

	static DWORD __stdcall foo(void* temp){			//넘겨받은 this포인터를 Thread로 casting한다. 그 후 멤버함수인 foo함수를 호출한다.
		Thread* self = static_cast<Thread*>(temp);	
		self->foo();								//다시 가상함수를 호출한다. 즉 foo(this)가 되어야 한다.
		return 0;
	}
	
	virtual void foo(){
		cout << "Thread" << endl;
	}
};

class MyThread : public Thread{
public:
	virtual void foo(){					//이 함수가 오버라이딩 되고 Thread내부에서 실행되어야 한다.
		cout << "MyThread" << endl;
	}
};

int main(){
	Thread* t = new MyThread;
	t->create();
	
	_getch();
	return 0;
}

//결론.
//Thread를 객체화 시키기 위해 static 멤버함수를 만들어 CreateThread의 인자로 주었다.
//상속을 통해 오버라이딩이 가능하도록 해야한다. 하지만 static에서 this란 있을 수 없다.
//그러므로 void*를 통해 this를 넘겨받고 그것을 casting 하여 다시 virtual 멤버 함수를 호출한다.
//객체형 Thread를 구현하였다.
//이점.
//복잡한 생성과정 제거
//재사용성 증가