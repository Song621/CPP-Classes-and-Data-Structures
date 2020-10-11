# 1.2类的基本概念
像结构一样，类是用来生成对象的蓝图，而且由同一个类可以生成一个以上的对象。这样的对象是一种非常流行的编程风格的基础，这种编程风格就是面向对象编程（object-oriented programming, OOP）。

类生成的对象除了 ***包含常规的数据成员外，通常还包含函数成员***。其次，在正确编写的类中，程序只能访问由类生成的对象的函数。结构对象的数据成员很容易被访问，但是 ***正确编写的类的对象的数据成员却根本无法访问***。对象内部的数据只能由对象本身访问。我们称这一特性为**封装**，这是因为数据位于容器内，也就是数据位于对象内部，对程序的其他部分隐身。出于该原因，认为由类生成的对象与程序的其他部分是分离的。事实证明，***封装是OOP的一大优点***，我们可以修改类中数据的类型，而不影响程序的其他部分。

# 1.3 类的实现
**实现（implementation）**

每个类应该使用2个文件
* 类说明文件(class specification file)
* 类实现文件(class implementation file)

类说明文件仅包含类的定义，除了包含数据成员的声明外，还包含函数的原型。实现文件中包含有类定义中函数原型的所有函数定义。

***编写类时，考虑主程序员就可以了。***

通常将主程序称为客户程序(client program)，而将主程序员称为客户(client)。

# 1.4 类的测试
编写好类时，应该在使用之前对类进行测试。类的测试方式，就是编写一个主程序来使用类的每一个函数，确保每一个函数都能完成预定的功能。当所编写的主程序只是用于测试目的时，就把这个主程序称为**测试驱动程序(test driver)**，或者简称为驱动程序。

# 1.5 将函数定义放在类定义中
将具有函数原型的函数定义放在类定义中。**仅当函数定义中没有几行代码时才可以使用这种技术，也不该有if语句或者循环**。

使用这种技术重写Checkbook类：

```C++
class Checkbook
{
    //依据惯例，函数原型位于共用部分，数据成员位于私有部分
    //有时候函数原型也位于私有部分，但是仅类的设计人员不希望在对象之外调用这个函数时才使用这种方式。
    //类的设计人员希望该函数只能被对象内的其他函数调用
    public:
        void setBalance(float amount){balance = amount;}
        bool writeCheck(float amount);//return false if amount is greater than balance;
                                      //otherwise returns true
        void deposit(float amount){balance += amount; lastDeposit = amount;}
        float getBalance(){return balance;}
        float getLastCheck(){return lastCheck;}
        float getLaastDeposit(){return lastDeposit;}
    
    private:
        float balance;
        float lastCheck;
        float lastDeposit;
};
```

然后类实现文件如下：

```C++
bool Checkbook::writeCheck(float amount)
{
    if (amount > balance)
        return false;
    balance -= amount;
    lastCheck = amount;
    return true;
}
```

***不过，最好将类的代码保存在类实现文件中，原因之一就是因为这种方式便于代码的维护。***