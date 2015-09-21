//2. this3
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//this 관리의 어려움!
//thread는 다음과 같이 사용한다.

DWORD __stdcall foo(void* p){
	//cout << "foo" << endl;
	for (int i = 0; i < 10000; i++)cout << "@" << endl;
	return 0;
}

DWORD __stdcall goo(void* p){
	//cout << "foo" << endl;
	for (int i = 0; i < 10000; i++)cout << "*" << endl;
	return 0;
}

int main(){
	CreateThread(0, 0, foo, 0, 0, 0); // 스레드를 만드는 함수
	CreateThread(0, 0, goo, 0, 0, 0); // 스레드를 만드는 함수
	// 리눅스 : pthread_create()
	_getch();
}
//이를 객체화 시켜보자.