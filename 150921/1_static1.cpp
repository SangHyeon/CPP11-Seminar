//1. static1
//static�� ����ϴ� ������?
//���������� ����ϴ� ������?
//starcraft Unit�� ��ü ���� �����ϴ� class�� �����غ���.


#include <iostream>
using namespace std;


//���� ��ü�� ���� count�ϱ� ���� "���� ����"
int cnt;
class Unit{
public:
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
};

//��� Unit�� �����ڸ� ȣ���ϱ� ������ cnt�� �����Ѵ�.
class Zealot : public Unit{};

class Medic : public Unit{};


void test(){		//�Լ� ������ ��ü�� �����ǰ� �Լ��� ���� �� ��ü�� �Ҹ��Ѵ�.
	Zealot z1, z2;
	Medic m1, m2;

	cout << cnt << endl;
}

int main(){
	test();
	cout << cnt << endl;
	return 0;
}

//���. ���������� "�����Ǵ� ����" ��� ������ �ſ� �߿��ϴ�.