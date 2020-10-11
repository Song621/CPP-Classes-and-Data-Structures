#include <iostream>
#include "MinBalCheckBook.h"

using namespace std;
void foo(CheckBook<float> & cbook);

int main()
{
    CheckBook<float> cbook1(500);
    MinBalCheckBook<float> cbook2(1000,200,100,0.5F);

    //派生类对象的地址赋给基对象的指针。
    CheckBook<float> *ptr1 = &cbook2;

    foo(cbook1);
    cout<<cbook1.getBalance()<<endl;
    cout<<cbook1.err()<<endl;
    foo(cbook2);
    cout<<cbook2.getBalance()<<endl;
    cout<<cbook2.err2()<<endl;
    foo(*ptr1);
    cout<<ptr1->getBalance()<<endl;
    //(*ptr1).getBalance();//.运算符的优先级高于*运算符

    return 0;
}

void foo(CheckBook<float> & cbook)
{
    //在类中不使用virtual,就不考虑传给foo()函数的对象的类型，称为静态绑定(ststic binding)。
    cbook.writeCheck(200);
}