// MinBalCheckBook.h � a class template derived from the CheckBook class template// The constructor and the writeCheck function can exceptions if// out of heap memory.// to use a struct for the DataType, you must overload the following operators://	>	left operand:  struct object	right operand:  float//		used to compare the amount of the check in the struct object with the //		balance//	-=	left operand:  float		right operand:  struct object//		used to subtract the amount of the check in the struct object from the//		balance#include "CheckBook.h"template <class DataType>class MinBalCheckBook : public CheckBook<DataType>{public:	MinBalCheckBook( float initBalance, float minBalance, float sfee, float cfee );	virtual bool writeCheck( const DataType & amount );  // returns false if amount is 		                                 // greater than balance; otherwise returns true	void deductServiceFee( );private:		float minBalance;	float serviceFee;	float checkFee;};#include "MinBalCheckBook.cpp"