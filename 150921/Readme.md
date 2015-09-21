##C++11 Seminar - 15.09.21 (강사 : 임인섭)

####*C++에서의 Template*
- **STL**(중요)
- **boost** library

####*static variable* (공유 변수)
- 전역 변수와 지역 변수의 장점들을 가지고 있음
	- 전역 변수인데 영역이 한정되어 있음! (class 안에 선언되어 있으면 범위는 class내)
	- class에서 사용하는 경우 private에 선언하는 걸 추천 (접근하기 위해 함수 선언) -> 캡슐화
- 전역 변수를 선언하게 될 때는 항상 신중히 선언해야 한다. (규모가 커질수록 복잡해짐)
	- 나중에 코드를 공유할 때 모든 부분에서 접근이 가능하기 때문에 문제가 생길 수 있음
	- 변수명을 다양하게 선언할 수 없음(전역 변수와 겹치는 경우...)
- 그래서 **static**을 사용!!
- 함수에도 사용 가능
	- 그냥 멤버 함수로 선언했을 때 사용하기 위해서는 객체를 생성해야함 -> 메모리 낭비
	- 전역 함수처럼 사용하고 싶을 때
- 객체지향 프로그래밍에서는 전역 변수를 사용하지 않도록 한다

######결론 : 공유 변수 -> 공유 영역을 가짐 -> 코드 복잡도가 낮아짐

ex> 
`static int cnt;`
`static bool lineTntersect()`

객체가 없으면 한 번만 선언하도록 하기 (singleton pattern) -> singleton도 많이 쓰면 복잡해짐...
```
class Share {
private:
	int cnt;
    static Share* instance;
public:
	static Share& getInstance() {
    	...
        return *instance;
    }
};
```

####*this pointer*
- 멤버 함수 전달인자에 class_name* const this가 생략되어 있음
	- `a.f() == f(&a)`
	- `void f(A* const this) { ... }`

```
class A {
private:
	int a;
public:
	static void f() {
    	//a = 10; // Compile ERROR
    }
}
```
- Thread를 사용하면 this의 관리가 어렵다
	- 윈도우에서는 `#include<windows.h> -> CreatTread(...)` 함수 사용
- 왜?????
- thread를 객체화 시키고 상속받아서 사용하고 싶음(virtual) -> window에는 수행할 함수에 this가 있으면 실행시킬 수 없다. (CreatThread(...) compile error) -> 함수 형식이 다름
	- static은 thread로 넘길수 있으나 thread class를 사용할 수 없다.
- static에 this pointer를 인자로 넘겨준다!
```
다시 정리
class Thread {
public:
	void creat() {
    	CreatThread(0, 0, foo, this, 0, 0);
    }
	virtual void foo() {...}
	static foo(void*){
		static_cast<Tread*>(p)->foo();
	}
}
```

####*virtual* (가상 함수)
- 사용 이유
	- 다형성
- 사용한 객체와 사용하지 않은 객체의 크기는 서로 다르다!
	- 가상 함수 테이블을 만듦
	- 가장 적절한 가상 함수를 사용
	- 가상 함수를 사용하는 객체의 크기가 더 큼(테이블 때문에)
	- 가상 함수를 사용하는 객체를 상속받는 객체도 테이블을 갖는다.
	- `p->print() == p->vptr->vtable->(적절한)print()`


