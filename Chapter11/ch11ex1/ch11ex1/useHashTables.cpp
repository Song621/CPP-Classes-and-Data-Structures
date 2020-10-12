#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

struct MyStruct{
    string str;
    int num{};
    bool operator ==(const MyStruct & r) {return str == r.str;}
};

const int SIZE1 = 97, SIZE2 = 199;

int hash1(const MyStruct & obj);
int hash2(const MyStruct & obj);

int main()
{
    HashTable<MyStruct> ht1(hash1, SIZE1), ht2(hash2, SIZE2);

    MyStruct myobj;

    myobj.str = "elephant";
    myobj.num = 25;
    ht1.insert(myobj);

    myobj.str = "giraffe";
    myobj.num = 50;
    ht2.insert(myobj);

    MyStruct myobj2;

    myobj2.str = "elephant";
    ht1.retrieve(myobj2);
    cout << "retrieved from ht1: " << myobj2.num << " for num." <<endl;
    cout << myobj2.str << endl;

    myobj2.str = "giraffe";
    ht2.retrieve(myobj2); 
    cout << "retrieved from ht2: " << myobj2.num << " for num." <<endl;
    cout << myobj.str << endl;

    return 0;
}

int hash1(const MyStruct & obj)
{
    int sum = 0;
    for(int i = 0; i < 3 && i < int(obj.str.length()); i++)
        sum += obj.str[i];
    return sum % SIZE1;
}

int hash2(const MyStruct & obj)
{
    int sum = 0;
    for(int i = int(obj.str.length()) - 1; i > -1 && i > int(obj.str.length()) - 7; i--)
        sum += obj.str[i];
    return sum % SIZE2;
}