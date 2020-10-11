//#pragma once
#include "CheckBook.h"

template <class DataType>
class MinBalCheckBook:public CheckBook<DataType>
{
    public:
        MinBalCheckBook(float initBalance, float minBal, float sfee, float cfee);
        bool writeCheck(const DataType & amount);
        void deductServiceFee();
    private:
        float minBalance;
        float serviceFee;
        float checkFee;
};

template <class DataType>
MinBalCheckBook<DataType>::MinBalCheckBook(float initBalance, float minBal, float sFee, float cFee)
	: CheckBook<DataType>(initBalance), minBalance(minBal), serviceFee(sFee), checkFee(cFee)
{
}

// returns false if amount is greater than balance; otherwise returns true
template <class DataType>
bool MinBalCheckBook<DataType>::writeCheck(const DataType & amount)
{
    //CheckBook<DataType>::balance;
	bool success = CheckBook<DataType>::writeCheck(amount);

	if (success && CheckBook<DataType>::balance < minBalance)
		CheckBook<DataType>::balance -= checkFee;

	return success;
}

template <class DataType>
void MinBalCheckBook<DataType>::deductServiceFee()
{
	if (CheckBook<DataType>::balance < minBalance)
		CheckBook<DataType>::balance -= serviceFee;
}
