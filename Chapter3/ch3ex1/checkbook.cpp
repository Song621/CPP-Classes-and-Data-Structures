//checkbook.cpp - The functions for the Checkbook class
/*#include "checkbook.h"


//�����ܷ������ݳ�Ա��ͨ�����ú���������˽�б�����ֵ
template <class DataType>
void Checkbook<DataType>::setBalance(float amount)
{
	balance = amount;//balance��������Ķ��������������ÿ��������֪���ඨ���е����ݳ�Ա
}

//���˵������˻���ȡǮ
template <class DataType>
bool Checkbook<DataType>::writeCheck(DataType & amount)
{
	if (amount > balance)
		return false;
	balance -= amount;
	lastCheck = amount;
	return true;
}

//���
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