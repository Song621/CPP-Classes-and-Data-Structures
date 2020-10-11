//指针和动态数组
#include <iostream>

using namespace std;

int main()
{
    int num[5];//int *ptrToArray = num;num存储的是数组的地址，
    //ptrToArray存储的也是数组的地址，但是数组名num并不是指针，
    //因为指针定义为一个存储地址的变量，它的值是可以改变的。
    int sum = 0, sum2 = 0;

    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter element "<<i<<": ";
        cin>>num[i];
    }

    //[]运算符
    for (int i = 0; i < 5; i++)
    {
        sum = sum + num[i];//操作数是num和i，运算结果是一个位置，*(num+i),num+i是一个地址结果，因此我们可以取这个地址中的内容，获得它的位置
        //C++计算结果地址的方式是首先查看表达式中所使用地址的数据类型（存储在num中），
        //然后，C++将这个整型数乘以该数据类型的字节数。
        sum2 = sum2 + i[num];//加法可交换，*(num+i)
    }

    cout<<"The resulting sum is: "<<sum<<endl;
    cout<<"The resulting sum2 is: "<<sum2<<endl;
    return 0;
}