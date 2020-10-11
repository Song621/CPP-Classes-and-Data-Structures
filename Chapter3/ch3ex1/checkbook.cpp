//checkbook.cpp - The functions for the Checkbook class
/*#include "checkbook.h"


//程序不能访问数据成员，通过调用函数来设置私有变量的值
template <class DataType>
void Checkbook<DataType>::setBalance(float amount)
{
	balance = amount;//balance变量在类的定义中声明，类的每个函数都知道类定义中的数据成员
}

//开账单，从账户中取钱
template <class DataType>
bool Checkbook<DataType>::writeCheck(DataType & amount)
{
	if (amount > balance)
		return false;
	balance -= amount;
	lastCheck = amount;
	return true;
}

//存款
template <class DataType>
void Checkbook<DataType>::deposit(float amount)
{
	balance += amount;
	lastDeposit = amount;
}

template <class DataType>
float Checkbook<DataType>::getBalance()
{
	return balance;
}

template <class DataType>
DataType Checkbook<DataType>::getLastCheck()
{
	return lastCheck;
}

template <class DataType>
float Checkbook<DataType>::getLaastDeposit()
{
	return lastDeposit;
}
*/