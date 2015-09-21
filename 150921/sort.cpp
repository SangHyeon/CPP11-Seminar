#include <iostream>
#include <algorithm>	//sort ���
#include <vector>		//vector ���
using namespace std;

class Point{			//��
public:
	int x, y;
	Point():x(0),y(0){}
	Point(int x, int y) :x(x), y(y){}
	bool operator<(const Point& a){
		return x < a.x;
	}
};

bool compare(Point a, Point b){
	return a.x < b.x;
}

bool compare2(Point a, Point b){
	return a.y < b.y;
}

bool compare3(Point a, Point b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(){
	vector<Point> v;
	v.push_back(Point(1, 32));	//vector�� Point�� �ִ´�.
	v.push_back(Point(2, 24));
	v.push_back(Point(4, 12));
	v.push_back(Point(5, 12));
	v.push_back(Point(-9, 23));
	v.push_back(Point(154, 2));
	v.push_back(Point(1, 23));
	v.push_back(Point(11, 2));

	//std::sort(begin(v), end(v));			//�ƹ��� ������ �Լ������ͷ� ���� �ʴ� ��� (��ü < ��ü) �����ε� �� ��� operator< �����ڸ� ������ �ؾ��Ѵ�.
	std::sort(begin(v), end(v), compare);	//x���� ����
	std::sort(begin(v), end(v), compare2);	//y���� ����
	std::sort(begin(v), end(v), compare3);	//x���� ����, x�� ������ y���� ����

	for (int i = 0; i < v.size(); i++){
		cout <<"("<< v[i].x<<" "<<v[i].y << ") ";
	}
	return 0;
}