//2. this3
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//this ������ �����!
//thread�� ������ ���� ����Ѵ�.

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
	CreateThread(0, 0, foo, 0, 0, 0); // �����带 ����� �Լ�
	CreateThread(0, 0, goo, 0, 0, 0); // �����带 ����� �Լ�
	// ������ : pthread_create()
	_getch();
}
//�̸� ��üȭ ���Ѻ���.