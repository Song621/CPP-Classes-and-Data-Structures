//#pragma once
#include "Array.h"

template <class DataType>
class CheckBook
{
    public:
        CheckBook(float initBalance);
        bool writeCheck(const DataType & amount);
        void deposit(float amount);
        float getBalance() const;
        Array<DataType> getChecks();
        float getLastDeposit() const;
	protected:
        float balance;
    private:
        int lastIndex;
        Array<DataType> checks;
        float lastDeposit;
};

template <class DataType>
CheckBook<DataType>::CheckBook(float initBalance)
:balance(initBalance),lastIndex(-1),checks(2)//初始化列表(initializer list)
{//当位于私有部分中的对象是没有默认构造函数（没有参数的构造函数）的数据成员时，就必须使用初始化列表。
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
