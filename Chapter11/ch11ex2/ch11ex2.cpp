// ch11ex2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

struct MyStruct {
    string str;
    int num{};
    bool operator ==(const MyStruct& r) { return str == r.str; }
};

const int SIZE1 = 97, SIZE2 = 199;

int hash1(const MyStruct& obj);
int hash2(const MyStruct& obj);

int main()
{
    
    DoublyLinkedList<MyStruct> ht1(hash1, SIZE1);

    MyStruct myobj;

    myobj.str = "elephant";
    myobj.num = 25;
    ht1.insert(myobj);

    myobj.str = "giraffe";
    myobj.num = 50;
    ht1.insert(myobj);

    MyStruct myobj2;

    myobj2.str = "elephant";
    ht1.retrieve(myobj2);
    cout << "retrieved from ht1: " << myobj2.num << " for num." << endl;
    cout << myobj2.str << endl;

    return 0;
}

int hash1(const MyStruct& obj)
{
    int sum = 0;
    for (int i = 0; i < 3 && i < int(obj.str.length()); i++)
        sum += obj.str[i];
    return sum % SIZE1;
}

int hash2(const MyStruct& obj)
{
    int sum = 0;
    for (int i = int(obj.str.length()) - 1; i > -1 && i > int(obj.str.length()) - 7; i--)
        sum += obj.str[i];
    return sum % SIZE2;
}

