//1. static3
//������ ��������� �����غ��� ���ٱ����� ��������.


#include <iostream>
using namespace std;

//������Ȳ.
//�ܺο��� Unit�� cnt���� ���� �ٲ� ���� �ִ�.
//�̷��� ���ɼ��� �־�� �ȵȴ�.


//�ذ�.
//���� ������ ����. (Encapsulation)
class Unit{
private:
	static int cnt;			//Unit class���� ��ȿ�� �������� cnt�� ������
public:
	Unit(){ cnt++; }
	~Unit(){ cnt--; }
	static const int& get_cnt() { return cnt; }		//�ܺο��� cnt�� ���� ������ ���� ��
};
int Unit::cnt = 0;

class Zealot : public Unit{};
class Medic : public Unit{};

void test(){
	Zealot z1, z2;
	Medic m1, m2;

	cout << Unit::get_cnt() << endl;
}

int main(){
	test();
	cout << Unit::get_cnt() << endl;
	return 0;
}

//���. ���ٱ����� �����ν� �Ϻ��� ��üȭ(Encapsulation)
//�ܺο��� ���ٵǴ� ���ɼ��� ������ �ʴ´�.