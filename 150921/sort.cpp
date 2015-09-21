#include <iostream>
#include <algorithm>	//sort 사용
#include <vector>		//vector 사용
using namespace std;

class Point{			//점
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
	v.push_back(Point(1, 32));	//vector에 Point를 넣는다.
	v.push_back(Point(2, 24));
	v.push_back(Point(4, 12));
	v.push_back(Point(5, 12));
	v.push_back(Point(-9, 23));
	v.push_back(Point(154, 2));
	v.push_back(Point(1, 23));
	v.push_back(Point(11, 2));

	//std::sort(begin(v), end(v));			//아무런 전략을 함수포인터로 받지 않는 경우 (객체 < 객체) 형태인데 이 경우 operator< 연산자를 재정의 해야한다.
	std::sort(begin(v), end(v), compare);	//x기준 정렬
	std::sort(begin(v), end(v), compare2);	//y기준 정렬
	std::sort(begin(v), end(v), compare3);	//x기준 정렬, x가 같으면 y기준 정렬

	for (int i = 0; i < v.size(); i++){
		cout <<"("<< v[i].x<<" "<<v[i].y << ") ";
	}
	return 0;
}