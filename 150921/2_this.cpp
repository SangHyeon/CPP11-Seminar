#include<iostream>
using namespace std;

class Dialog {
public:
    void goo() {cout<<"class goo"<<endl;}
};

void foo(){
    cout<<"function foo"<<endl;
};

int main() {
    //void(*pf)() = &foo;//return : void, para : void  //연산자 우선순위 때문에 *pf에 괄호 사용
    void(*pf)();
    pf = &foo;
    pf();//암시적 변환 : foo();와 같음

    //member function pointer
    //pf = &Dialog::goo(); // this pointer가 있어서 사용 못함
    Dialog a;
    void(Dialog::*g)(); //member function pointer // has this pointer
    g = &Dialog::goo;
    //a.g(); == g(&a);//ERROR
    (a.*g)(); // .* 연산자

    Dialog *b = new Dialog;
    (b->*g)(); // ->* 연산자

    return 0;
}
