#pragma once
#include "CheckBook.h"
template <class DataType>
class testclass :
	public CheckBook<DataType>
{
protected:
	int a;
};

