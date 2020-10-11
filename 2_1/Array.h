//Array.h -- class template for an adjustable array
#include <string>

using namespace std;

template <class DataType>
class Array
{
    public:
        Array(int size);
        inline DataType & operator [](int index);
        void changeSize(int newSize);
        inline int length() const;
        string err() const;
    private:
        DataType *elements;
        int capacity;
        DataType dud;
        int errorCode;
};
//#include "Array.cpp"