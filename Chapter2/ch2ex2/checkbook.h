//checkbook.h - A class for a checkbook, where the check is any data type
//to use a struct for the DataType, you must overload the following operators:
//	>	left operand: struct object;	right oprand: float;
//		used to compare the amount of the check in the struct object with the balance.
// -=	left operand: float;				right operand: struct object;
//		used to subtract the amount of the chenck in the struct object from the balance.
#pragma once
template <class DataType>
class Checkbook
{
	public:
		void setBalance(float amount);
		bool writeCheck(DataType amount);//return false if amount is greater than balance;
									  //otherwise returns true
		void deposit(float amount);
		float getBalance();
		DataType getLastCheck();
		float getLaastDeposit();

	private:
		float balance{};
		DataType lastCheck;
		float lastDeposit{};
};

//#include "checkbook.cpp"

/*
//�����ܷ������ݳ�Ա��ͨ�����ú���������˽�б�����ֵ
template <class DataType>
void Checkbook<DataType>::setBalance(float amount)
{
	balance = amount;//balance��������Ķ��������������ÿ��������֪���ඨ���е����ݳ�Ա
}

//���˵������˻���ȡǮ
template <class DataType>
bool Checkbook<DataType>::writeCheck(DataType amount)
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
