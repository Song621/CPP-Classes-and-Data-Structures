//#pragma once
#include "Array.h"

//当一个类的对象声明为另一个类的数据成员时，直到调用了包含类（这里指CheckBook类）的构造函数，才能调用这个类的构造函数。
//按传值方式将CheckBook传递给函数,会调用Array类的复制构造函数
//对于赋值，也会自动调用Array对象的重载赋值运算符
//当对象销毁时，会调用这个对象所包含所有对象（作为数据成员）的析构函数
template <class DataType>
class CheckBook
{
    public:
        CheckBook(float initBalance);
        bool writeCheck(const DataType & amount);
        void deposit(float amount);
        float getBalance() const;
        Array<DataType> getChecks();//一个类对象是另一个类对象的成员时->组合关系（composition）
        float getLastDeposit() const;
        string err() const;
	protected:
        float balance;
    private:
        int lastIndex;
        Array<DataType> checks;
        float lastDeposit;
        int mark;
};

template <class DataType>
CheckBook<DataType>::CheckBook(float initBalance)
:balance(initBalance),lastIndex(-1),checks(2),mark(0)//初始化列表(initializer list)
{
    //当位于私有部分中的对象是没有默认构造函数（没有参数的构造函数）的数据成员时，就必须使用初始化列表。
    //在这里，私有部分的对象是Array对象checks,必须为checks传递一个size，check(2)调用的是Array对象的构造函数
    //初始化列表中，可以将值赋予类的任意数据成员，但是，为非对象数据成员赋值不使用赋值运算符，要使用括号将所赋予的值括起来。
}

template <class DataType>
bool CheckBook<DataType>::writeCheck(const DataType & amount)
{
    if(amount > balance)
        return false;
    balance -= amount;

    if(lastIndex == checks.length()-1)
        checks.changeSize(2*checks.length());
    lastIndex++;
    checks[lastIndex] = amount;
    mark = 1;
    return true;
}

template <class DataType>
void CheckBook<DataType>::deposit(float amount)
{
	balance += amount;
	lastDeposit = amount;
}

template <class DataType>
float CheckBook<DataType>::getBalance() const
{
	return balance;
}

template <class DataType>
Array<DataType> CheckBook<DataType>::getChecks()
{
	Array<DataType> info(lastIndex+1);
    for (int i = 0, j = lastIndex; j >= 0; i++, j--)
    {
        info[i] = checks[j];
    }
    return info;
    
}

template <class DataType>
float CheckBook<DataType>::getLastDeposit() const
{
	return lastDeposit;
}

template <class DataType>
string CheckBook<DataType>::err() const
{
	if (mark == 1)
		return "CheckBook's writeBook!";
}