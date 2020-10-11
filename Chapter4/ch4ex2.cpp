//动态分配内存
#include <iostream>

using namespace std;

void foo();

int main()
{
    //动态分配内存来源于堆(heap)的使用
    //4.3 堆(heap)--一部分专门为程序应用设置的RAM
    //访问堆中内存的唯一方式就是使用new操作符，一元运算符，操作数是一个数据类型
    //new的操作结果是堆中一串内存的地址，它的结果几乎总是赋给指针。
    /*float *ptr;
    ptr = new float;
    *ptr = 1.5;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;*/

    //4.4 动态数组
    int *ptr;
    ptr = new int [5];
    ptr[3] = 25;
    //int num[5];//数组是声明的，称为静态数组。
    //动态数组的优点在于在代码编译时不需要知道数组的大小。
    int numElements;
    cout<<"How many elements would you like the array to have? ";
    cin>>numElements;
    float *ptrArr = new float [numElements];
    //在静态数组中，诸如numElements的变量是不能用来声明数组大小的。

    return 0;
}

void foo()
{
    int numElements;
    cout<<"How many elements would you like the array to have? ";
    cin>>numElements;
    float *ptrArr = new float [numElements];    

    delete [] ptrArr;//防止内存泄露，[]释放整个数组的元素时才使用，只释放一个单独的空间时就不需要[]
}