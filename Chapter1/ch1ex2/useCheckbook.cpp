//useCheckbook.cpp - A program for using the Checkbook class

#include <iostream>
#include <iomanip>
#include "checkbook.h"

using namespace std;

int menu();

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, QUIT = 4;

//1. 对象的私有数据成员不能在对象之外访问。只有对象自己才能访问它的私有数据成员。
//2. 从对象的函数返回时，对象将保留它的数据成员的当前值。因此，在调用对象的另一个函数时，这些值仍然保持不变。
//3. 类的所有函数都可以使用在类定义中声明的数据成员。主程序不能使用对象的私有数据成员，对私有数据成员也不了解。

//思考方式
//在编写类时的思考方式应为“考虑主程序员，不用再考虑用户了”
//“我怎样做才能使这个类让主程序员方便使用呢？”
//“这个类中我要设计一些什么样的对主程序员有用的函数呢？”
//“我如何才能让主程序员在使用我的类时拥有极大的灵活性呢？”等等问题
//出于这些原因，通常将主程序称为客户程序(client program),而将主程序员称为客户(client)。

//类的测试
//编写一个主程序来使用类的每一个成员函数，确保每个函数都能完成预定的功能。
//当所编写的主程序只是用作测试目的时，就把这个主程序称为测试驱动程序(test driver)，或者简称为驱动程序。
//一旦确定整个类工作正确，就可以抛弃测试这个类的驱动程序。
//这样看似会增大工作量，但是当程序中使用了大量的类时，若对类不进行测试，会极大的增加排除错误所需要的时间。

int main()
{
    Checkbook cb;//声明一个对象，对象与主程序是分离的，主程序无法访问类定义中声明的变量
    float balance,amount;
    int choice;
    cout<<"Enter the initial balance:$";
    cin>>balance;
    cb.setBalance(balance);

    cout<<fixed<<showpoint<<setprecision(2);
    choice = menu();

    while (choice != QUIT)
    {
        if (choice == CHECK)
        {
            cout<<"Enter chenck amount:$";
            cin>>amount;
            //有些程序员在writeCheck中向用户显示消息，若这样做，必须在类实现文件的顶部包含iostream文件，
            //这样才能在类函数中使用cout
            //但这种方法整个都是错的。主程序员可能喜欢你的消息也可能不喜欢你的消息，应该总让程序员决定程序应该对用户显示什么消息。
            if (cb.writeCheck(amount))
                cout<<"Chenck accepted."<<endl;
            else{
                cout<<"Your balance is not high enough for that check."<<endl;
            }
        }
        else if(choice == DEPOSIT){
            cout<<"Enter deposit amount:$";
            cin>>amount;
            cb.deposit(amount);
            cout<<"Deposit accepted."<<endl;
        }
        else{
            amount = cb.getBalance();
            cout<<"Your balance is:$"<<amount<<endl;
        }
        choice = menu();
    }

    return 0;
}

int menu()
{
    int choice;
    
    cout<<endl;
    cout<<"1 Write a check"<<endl;
    cout<<"2 Make a deposit"<<endl;
    cout<<"3 Get the balance"<<endl;
    cout<<"4 Quit"<<endl;
    cout<<"Enter a number between 1 and 4: ";
    cin>>choice;

    return choice;
}
