#pragma once
#include "Array.h"

//栈的数组实现
template <class DataType>
class Stack
{
public:
    Stack();
    void push(DataType elementToPush);
    bool pop(DataType & popedElement);
    bool peek(DataType & topElement);
    bool isEmpty() const;
    void makeEmpty();
private:
    int top;
    Array<DataType> elements;//两个类是组合关系
};

template <class DataType>
Stack<DataType>::Stack()
    :elements(2), top(-1)
{
}

//这里参数不是按照传常址方式传递，这是因为数组通常用于小规模元素大小的情况。
template <class DataType>
void Stack<DataType>::push(DataType elementToPush)
{
    if(++top == elements.length())
        elements.changeSize(elements.length()<<1);//移位运算符运算速度更快
    elements[top] = elementToPush;
}

template <class DataType>
bool Stack<DataType>::pop(DataType & popedElement)
{
    if(top == -1)
        return false;
    popedElement = elements[top];
    top--;

    int trysize = elements.length();
    while (top+1 <= trysize>>2 && trysize > 2)
    {
        trysize >>= 1;
    }

    if (trysize < elements.length())
    {
        try{
            elements.changeSize(trysize);
        }
        catch(...){}
    }
    
    return true;
}

template <class DataType>
bool Stack<DataType>::peek(DataType & topElement)
{
    if(top == -1)
        return false;
    
    topElement = elements[top];
    return true;
}

template <class DataType>
bool Stack<DataType>::isEmpty() const
{
    return top == -1;
}

template <class DataType>
void Stack<DataType>::makeEmpty()
{
    top = -1;
    try{
        elements.changeSize(2);
    }
    catch(...){}
}
