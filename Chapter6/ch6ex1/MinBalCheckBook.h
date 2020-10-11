//#pragma once
#include "CheckBook.h"

//继承（inheritance）
//基类（base）
//派生类（derived）
//客户声明一个派生类时，将同时生成一个基对象和一个派生对象，基对象是派生对象的一部分
//几乎所有基对象中的公用元素都可以由派生对象使用；除了所有的构造函数（包括复制构造函数）、析构函数和重载运算符=函数外
//派生类从基类中继承所有的公用函数，私有数据成员、私有函数是不继承的。
//若希望从基类中继承数据成员或者私有函数。然而又不宜将它们声明为公用的，在基类中使用保护(protected)部分
//对客户程序来说，保护（protected）部分的使用方式像私有部分一样；但对于派生类来说，它的使用方式就像公用部分一样，
//因此，派生类可以继承包含在受保护部分中的数据成员。

template <class DataType>
class MinBalCheckBook:public CheckBook<DataType>
{
    public:
        MinBalCheckBook(float initBalance, float minBal, float sfee, float cfee);
        bool writeCheck(const DataType & amount);
        void deductServiceFee();
		string err2();
    private:
        float minBalance;
        float serviceFee;
        float checkFee;
		int mark2;
};

//调用构造函数的唯一方法就是在对象的声明中，基对象的构造函数必须使用派生类的构造函数调用
//基对象没有名称，因此只使用类类型将参数传递给基类的构造函数
template <class DataType>
MinBalCheckBook<DataType>::MinBalCheckBook(float initBalance, float minBal, float sFee, float cFee)
	: CheckBook<DataType>(initBalance), minBalance(minBal), serviceFee(sFee), checkFee(cFee),mark2(0)
{
}

// returns false if amount is greater than balance; otherwise returns true
template <class DataType>
bool MinBalCheckBook<DataType>::writeCheck(const DataType & amount)
{
	bool success = CheckBook<DataType>::writeCheck(amount);

	if (success && CheckBook<DataType>::balance < minBalance)
		CheckBook<DataType>::balance -= checkFee;//访问带有类模板的成员好像要写上类名
	mark2 = 1;
	return success;
}

template <class DataType>
void MinBalCheckBook<DataType>::deductServiceFee()
{
	if (CheckBook<DataType>::balance < minBalance)
		CheckBook<DataType>::balance -= serviceFee;
}

template <class DataType>
string  MinBalCheckBook<DataType>::err2()
{
	if (mark2 == 1)
		return "MinBalCheckBook's writeCheck";
	else
		return "no";
}