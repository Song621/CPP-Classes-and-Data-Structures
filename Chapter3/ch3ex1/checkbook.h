//checkbook.h - A class for a checkbook, where the check is any data type
//to use a struct for the DataType, you must overload the following operators:
//	>	left operand: struct object;	right oprand: float;
//		used to compare the amount of the check in the struct object with the balance.
// -=	left operand: float;				right operand: struct object;
//		used to subtract the amount of the chenck in the struct object from the balance.
#pragma once
const int CAPACITY = 5;
template <class DataType>
struct CheckInfo
{
	int numChecks;
	DataType checks[CAPACITY];
};
template <class DataType>
class Checkbook
{
	public:
		Checkbook();//没有参数的构造函数->默认构造函数 //构造函数(constructor)通常用来初始化私有类的数据成员，声明对象时调用
		Checkbook(float initBalance);
		void setBalance(float amount);
		bool writeCheck(const DataType & amount);//return false if amount is greater than balance;
									  //otherwise returns true
		void deposit(float amount);
		float getBalance() const;//类成员函数的尾部可以加const，表示该函数不会修改所处类的数据成员，单独的函数后面不能加const
		DataType getLastCheck() const;
		CheckInfo<DataType> getLastChecks() const;
		float getLastDeposit() const;

	private:
		float balance;
		int numChecks;//the number of checks stored in the array
		int lastIndex;//the index of the last check that was written
		DataType lastChecks[CAPACITY];//saves up to CAPACITY checks
		float lastDeposit;
};

//#include "checkbook.cpp

template <class DataType>
Checkbook<DataType>::Checkbook()
{
	lastIndex = -1;
	numChecks = 0;
}

template <class DataType>
Checkbook<DataType>::Checkbook(float initBalance)
{
	balance = initBalance;
	lastIndex = -1;
	numChecks = 0;
}

//程序不能访问数据成员，通过调用函数来设置私有变量的值
template <class DataType>
void Checkbook<DataType>::setBalance(float amount)
{
	balance = amount;//balance变量在类的定义中声明，类的每个函数都知道类定义中的数据成员
}

//开账单，从账户中取钱
template <class DataType>
bool Checkbook<DataType>::writeCheck(const DataType & amount)
{
	if (amount > balance)
		return false;
	balance -= amount;

	lastIndex++;
	if (lastIndex == CAPACITY)
		lastIndex = 0;
	lastChecks[lastIndex] = amount;

	if (numChecks != CAPACITY)
		numChecks++;
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
float Checkbook<DataType>::getBalance() const
{
	return balance;
}

template <class DataType>
DataType Checkbook<DataType>::getLastCheck() const
{
	return lastChecks[lastIndex];
}

template <class DataType>
CheckInfo<DataType> Checkbook<DataType>::getLastChecks() const
{
	CheckInfo<DataType> info;
	info.numChecks = numChecks;

	for (int i = 0, j = lastIndex; i < numChecks; i++, j--)
	{
		if (j == -1)
			j = CAPACITY - 1;
		info.checks[i] = lastChecks[j];
	}
	return info;
}

template <class DataType>
float Checkbook<DataType>::getLastDeposit() const
{
	return lastDeposit;
}

