//1. static5
//���������� ��������� �ִٸ�, ������ �°� static ������ ����� ���� ���α׷��� ���⵵�� �����.
//�׷��ٸ� ������ ���� ���� ��Ѱ�?

#include <iostream>
using namespace std;

//������Ȳ. A�� B�� ���� count�ϰ� �ʹ�.
//������ �޸� ��Ӱ��谡 ����.

/*
int cnt;
class A{
	A(){ cnt++; }
	~A(){ cnt++; }
};

class B{
	B(){ cnt++; }
	~B(){ cnt++; }
};
*/

//���������� ���α׷��� ���⵵�� ������Ű�� ������ �ִ��� ������� �ʾƾ� �Ѵ�.
//�ذ�.
//�� ��� �����Ǵ� ������ ��ü�� ���Ѵ�.
//�� ��ü�� getInstance() �޼���θ� ȣ���� �����ϰ�, �� �ѹ��� �����ȴ�.
//�� ��ü�� cnt�� ���� getter ������ ���� �Լ��� ����
//���������� naming ������ ���ٱ��� ������ �ذ�(Singleton Pattern)
class ShareVal{
private:
	int cnt;
	static ShareVal* instance;
public:
	ShareVal():cnt(0){}
	// ���� �ϳ��� ��ü�� ���� �����ϴ� ���� �Լ�
	static ShareVal& getInstance(){
		if (instance == 0){
			instance = new ShareVal;
		}
		return *instance;
	}
	const int& get_cnt()const{ return cnt; }	//cnt ��ȯ
	void increase_cnt(){ this->cnt++; }			//cnt ����
	void decrease_cnt(){ this->cnt--; }			//cnt ����
};
ShareVal* ShareVal::instance = 0;


class A{
public:
	A(){ ShareVal::getInstance().increase_cnt(); }	//ShareVal class�� instance�� �ҷ��� cnt�� �����Ѵ�.
	~A(){ ShareVal::getInstance().decrease_cnt(); }
};

class B{
public:
	B(){ ShareVal::getInstance().increase_cnt(); }
	~B(){ ShareVal::getInstance().decrease_cnt(); }
};

void test(){
	A a1, a2;
	B b1, b2;

	cout << ShareVal::getInstance().get_cnt() << endl;	//ShareVal class�� instance�� �ҷ��� cnt�� ��ȯ
}

int main(){
	test();
	cout << ShareVal::getInstance().get_cnt() << endl;
	return 0;
}

//���. Singleton ������ �̿��Ͽ� ���� �ٸ� ��ü �� ���������� naming������ ���ٱ��� ������ �ذ�
//������ Singleton��ü�� �ʹ� ������ �� ���� ���α׷��� ���⵵�� ������Ų��. (Singleton�� ������ ���� ���� ��� �Ŀ� ��������.)