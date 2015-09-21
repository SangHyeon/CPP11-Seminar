//2. this1
#include <iostream>
using namespace std;

//class�� ����Լ��� ���� ������ ����.
//class�� ����Լ��� class�� ��������� ������ �� �ִ�. ���?


class Point{
	int x, y;
public:
	void set(int a, int b){
		//��� ���⿡�� this��� �����Ͱ� ���� �Ǿ��ִ�.
		x = a;
		y = b;
	}

	//�׷��� ��� �� �Լ��� �Ʒ��� ���� �����.
	//void set(Point* const this, int a, int b){
	//	this->x = a;
	//	this->y = b;
	//}

	//�׷� static �Լ��� ���??
	//static�Լ��� �����Լ��� ����. this ���ڰ� �Լ� ���ڷ� ���� �ʴ´�.
	static void foo(int a){		// void foo( int a )

		x = a;		// this->x = a �� �Ǿ� �ϴµ� this�� ����.
	}				// �׷��� static ��������� ��� ������ ������ �Ұ����ϴ�.

};




int main(){
	Point::foo(10); // static ����Լ��� ��ü���� ȣ�Ⱑ��

	Point p1, p2;
	p1.set(10, 20); // �� ������ ������ ������ ���ô�..
}					// set(&p1, 10, 20) ���� ����˴ϴ�.


//���.
// 1. ��� �Լ��� ȣ�� ����
//    ��ü�� �Լ��� 1��° ����(this)�� �߰��ȴ�. - this call
// 2. static ��� �Լ��� this �� �߰����� �ʴ´�.!!







