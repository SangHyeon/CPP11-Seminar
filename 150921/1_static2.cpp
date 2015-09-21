//1. static2
//static�� ����ϴ� ������?
//���������� �������� �����غ���.


#include <iostream>
using namespace std;

//������Ȳ.
//�������� cnt�� ������ �ʹ� �д�. ���α׷� ��ü�� ���� ������ ��ģ��.
//�� ������ ���α׷��� �ұԸ��� ���� �ɰ����� ������, ��Ը��� ���� �ɰ�������.

//��� �����Ǵ� ������ �� ��������� �ִ�.
//�׷��� ��������ó�� "�����Ǵ� ����"��� �Ӽ��� ������, ��������ó�� ��������� ������ų �� ������?
/*int cnt;
class Unit{
public:
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
};*/

//�ذ�.
//�׷��� static Ű���尡 ź����
class Unit{
public:
	static int cnt;				//Unit class���� ��ȿ�� �������� cnt�� ������
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
};
int Unit::cnt = 0;				//static ������ �ʱ�ȭ ���

class Zealot : public Unit{};
class Medic : public Unit{};

void test(){
	Zealot z1, z2;
	Medic m1, m2;

	cout << Unit::cnt << endl;	//static ������ ����
}

int main(){
	test();
	cout << Unit::cnt << endl;

	//������ �� ��쿡 ���� �����غ���.
	Unit::cnt = 7;
	//Unit�̶�� class �ܺο��� cnt�� ������ �ʿ䰡 ������?
	return 0;
}
