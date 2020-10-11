//checkbook.cpp - The functions for the Checkbook class

//双引号是为了向编译器表明需要包含的文件位于和.cpp文件同一个目录中
//尖括号像编译器表明所包含的文件位于头文件的库中
# include "checkbook.h"

//程序不能访问数据成员，通过调用函数来设置私有变量的值
void Checkbook::setBalance(float amount)
{
    balance = amount;//balance变量在类的定义中声明，类的每个函数都知道类定义中的数据成员
}

//开账单，从账户中取钱
bool Checkbook::writeCheck(float amount)
{
    if (amount > balance)
        return false;
    balance -= amount;
    lastCheck = amount;
    return true;
}

//存款
void Checkbook::deposit(float amount)
{
    balance += amount;
    lastDeposit = amount;
}

float Checkbook::getBalance()
{
    return balance;
}

float Checkbook::getLastCheck()
{
    return lastCheck;
}

float Checkbook::getLaastDeposit()
{
    return lastDeposit;
}