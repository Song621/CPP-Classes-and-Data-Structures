#include <iostream>

using namespace std;

void foo(int a, int b)
{
    cout<<"a is: "<<a<<endl;
    cout<<"b is: "<<b<<endl;
}

int main()
{
    void (*fptr) (int a, int b);
    //函数指针，指针名为fptr，*fptr两边的小括号是必须的，
    //fptr可以指向的函数的返回类型位于指针名称的左边，
    //指针函数的参数列表位于指针名称的右边。

    fptr = foo;//将foo的地址赋给fptr
    fptr(10,25);//通过使用指针来执行函数，我们不必取fptr指针的内容

    return 0;
}