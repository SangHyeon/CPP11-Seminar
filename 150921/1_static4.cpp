//1. static4
//static 함수를 사용하는 경우
//전역변수와 마찬가지로 전역함수도 영향을 미치는 범위가 있다면 그에 속하도록 하자.


#include <iostream>
using namespace std;

//점
class Point{
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int x, int y) :x(x), y(y) {}
};

//선
class Line{
	Point a, b;
public:
	Line() : a(), b() {}
	Line(Point a, Point b) : a(a), b(b) {}
	
	//이 경우 문제가 무엇일까?
	//line의 교차여부를 확인하고 싶을 뿐인데 꼭 line의 인스턴스를 통해서 확인하여야 하는가?
	/*bool lineIntersect(Line a, Line b){
		return true;
	}*/

	//static 함수로 구현한다.
	//lineIntersect 함수는 전역함수와 동일하지만 Line에 속해 있을 뿐이다.
	static bool lineIntersect(Line a, Line b){
		return true;
	}
};

//lineIntersect 함수는 Line class와 연관되어있는 함수이다.
//그러므로 class 내부에 넣자.
//선의 교차여부
/*bool lineIntersect(Line a, Line b){
	return true;
}*/


int main(){
	Line::lineIntersect(Line(Point(1, 2), Point(3, 4)), Line(Point(2, 5), Point(3, -4)));
	return 0;
}

//결론. lineIntersect라는 전역함수의 scope을 Line으로 한정하여 naming 문제 해결, 가독성 증가