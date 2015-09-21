//1. static4
//static �Լ��� ����ϴ� ���
//���������� ���������� �����Լ��� ������ ��ġ�� ������ �ִٸ� �׿� ���ϵ��� ����.


#include <iostream>
using namespace std;

//��
class Point{
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}
};

//��
class Line{
	Point a, b;
public:
	Line() : a(), b() {}
	Line(Point a, Point b) : a(a), b(b) {}
	
	//�� ��� ������ �����ϱ�?
	//line�� �������θ� Ȯ���ϰ� ���� ���ε� �� line�� �ν��Ͻ��� ���ؼ� Ȯ���Ͽ��� �ϴ°�?
	/*bool lineIntersect(Line a, Line b){
		return true;
	}*/

	//static �Լ��� �����Ѵ�.
	//lineIntersect �Լ��� �����Լ��� ���������� Line�� ���� ���� ���̴�.
	static bool lineIntersect(Line a, Line b){
		return true;
	}
};

//lineIntersect �Լ��� Line class�� �����Ǿ��ִ� �Լ��̴�.
//�׷��Ƿ� class ���ο� ����.
//���� ��������
/*bool lineIntersect(Line a, Line b){
	return true;
}*/


int main(){
	Line::lineIntersect(Line(Point(1, 2), Point(3, 4)), Line(Point(2, 5), Point(3, -4)));
	return 0;
}

//���. lineIntersect��� �����Լ��� scope�� Line���� �����Ͽ� naming ���� �ذ�, ������ ����