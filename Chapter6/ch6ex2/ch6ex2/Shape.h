#pragma once
//包含一个或多个纯虚函数的类称为抽象基类(bastract base class)
//无法由抽象基类生成对象，但是声明一个指向抽象基类对象的指针是完全合法的
class Shape
{
public:
	Shape();
	virtual float area() = 0;//表明这个类中没有area函数的定义，称为纯虚函数(pure virtual function)
};

