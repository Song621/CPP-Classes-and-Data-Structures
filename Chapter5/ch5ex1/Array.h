//Array.h -- class template for an adjustable array
//When debugging, use #define DEBUG_ARRAY above your #include Array line
#include <string>

using namespace std;

template <class DataType>
class Array
{
	public:
		//无论何时，只要类中有一个数据成员是指针时，就应该编写这3个函数：析构函数、复制构造函数和重载赋值运算符。
		Array(int size);//构造函数
		~Array();//析构函数
		//复制构造函数，
		//客户按传值方式向他的函数传递了一个Array对象，假定这个函数是foo。foo函数的形参对象自动地调用复制构造函数。
		Array(const Array<DataType> & ap);//ap是actual parameter（实参）的缩写，按传常址（引用调用）方式传递
		//返回类型是一个引用类型，允许返回位置，而不是值。
		inline DataType & operator [](int index);//函数调用通常都会有一定的开销，使用inline编译器会将函数的代码插入到函数调用的位置上
		                                         //若对类中的一个函数使用inline，那么整个函数定义需要放在类说明中（头文件.h中），编译器需要立刻查看到代码，从而对函数调用进行代码替换。
		void changeSize(int newSize);//will not alter values unless newSize is smaller than current capacity
		inline int length() const;//这样的函数称为访问器(accessor)
		string err() const;
		Array<DataType> & operator =(const Array<DataType> & right);
		//如果我们不使用重载赋值运算符，而且对象有一个数据成员是指针时，那么存储在赋值右边的对象的指针中的地址，
		//将存储到赋值左边的对象的相应指针中。
		//这就和按传值方式传递对象的问题一样，两个对象中的指针都指向内存中的同一个位置，因为它们拥有相同的地址。
		//另一个问题就是当修改一个对象的数组时，也将影响到另一个对象。可能会造成悬挂指针(dangling pointer)或者悬挂引用(dangling reference)。
	private:
		DataType* elements;
		int capacity;
		DataType dud;
		int errorCode;
		inline void deepCopy(const Array<DataType> & original);
};
//#include "Array.cpp"

template <class DataType>
Array<DataType>::Array(int size)
{
	if (size < 1)
	{
		capacity = 1;
		errorCode = 1;
	}
	else
	{
		capacity = size;
		errorCode = 0;
	}
	elements = new DataType[capacity];
}

template <class DataType>
Array<DataType>::~Array()
{
	delete [] elements;
}

//复制构造函数自动调用的三种情形：
//1. 按传值方式传递对象时会自动调用复制构造函数
//2. 当对象按传值方式从函数返回，且编写了复制构造函数时，也会自动调用复制构造函数
//3. 当对象声明过程中初始化时，Array<float> arr = arr2; 该语句调用的是arr对象的复制构造函数，而不是调用重载赋值运算符函数。
template <class DataType>
Array<DataType>::Array(const Array<DataType> & ap)
{
	deepCopy(ap);
}

template <class DataType>
inline DataType & Array<DataType>::operator [](int index)
{
#ifdef DEBUG_ARRAY
	if (index < 0 || index >= capacity)
	{
		errorCode |= 2;
		return dud;
	}
#endif
	return elements[index];
}

//在编写重载赋值运算符时，需要遵循以下原则：
//·检查是不是同一个对象（如第4行），如果对象相同，则返回* this。
//·释放左边对象中所有指针指向的动态内存。
//·调用deepCopy函数。
//·最后返回* this。
template <class DataType>
Array<DataType> & Array<DataType>::operator =(const Array<DataType> & right)
{
	if(this == &right)
		return *this;//this是一个关键字。
		//编译器将把它识别为拥有正在执行函数的对象的一个指针。
		//因此，在这种情况下，它就是赋值运算符左边对象的一个指针。
	delete [] elements;
	deepCopy(right);
	//关键字this可以在任何类或结构函数中使用。
	//如果单独使用this，它将给出拥有该函数的对象的地址。
	//如果解引用this，如下所示，将得到拥有该函数的实际对象。
	return *this;//我们返回的就是这个对象，这意味着它就是赋值运算的结果。
}

//在编写自己的deepCopy函数时，应遵循以下原则：
//1. 直接复制所有不是指针的数据成员；使用循环复制静态数组的元素
//2. 对指针数据成员进行深复制。也就是说，在堆中为它们分配动态内存，然后将所有的值复制到动态内存中。
//3. 如果没有足够的堆内存，deepCopy函数会抛出异常。在类说明文件中编写注释，让客户知道对象赋值和按传值方式传递可能会抛出异常。
template <class DataType>
inline void Array<DataType>::deepCopy(const Array<DataType> & original)
{
	capacity = original.capacity;
	errorCode = original.errorCode;
	elements = new DataType [capacity];
	for (int i = 0; i < capacity; i++)
		elements[i] = original.elements[i];
}

template <class DataType>
void Array<DataType>::changeSize(int newSize)
{
	if (newSize < 1)
	{
		errorCode |= 4;
		return;
	}

	DataType* newArray = new DataType[newSize];

	int limit = (newSize > capacity) ? capacity : newSize;

	for (int i = 0; i < limit; i++)
	{
		newArray[i] = elements[i];
	}

	delete[] elements;
	elements = newArray;
	capacity = newSize;
}


template <class DataType>
inline int Array<DataType>::length() const
{
	return capacity;
}


template <class DataType>
string Array<DataType>::err() const
{
	if (errorCode == 0)
	{
		return "No error.\n";
	}

	string errorMessage = "";
	if (errorCode & 1)
	{
		errorMessage += "Nonpositive size passed into constructor,so\n";
		errorMessage += "the capacity was set to 1 by default.\n";
	}
	if (errorCode & 2)
	{
		errorMessage += "Index out of range.\n";
	}
	if (errorCode & 4)
	{
		errorMessage += "Nonpositive size passed into changesize,so\n";
		errorMessage += "the size of the array was not changed";
	}
	return errorMessage;
}