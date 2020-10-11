#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct EngineType{
    int numCylinders;
    float numLiters;
    string countryMade;
} ;

//定义结构体,生成数据类型（自定义数据类型）
//声明用来告诉编译器变量的名称已经存在
//为了使用这个结构体，我们必须声明由结构体所定义的CarType类型的变量
//当变量由结构体声明时，就可以将变量成为对象（object）
struct CarType{
    //结构的元素称为数据成员
    string maker;
    int year;
    float price;
    //结构中声明的成员可以是数组，也可以是其他结构
    string wheel[4];
    EngineType engine;
    //engine还不是一个对象，一直要等到声明了一个CarType对象，否则它就不是一个对象——此时engine只是定义的一部分
    //我们要在CarType中使用EngineType结构，因此EngineType结构必须在CarType结构之前定义
};//一定要有分号

void getYourCar(CarType & car);

int main()
{
    CarType myCar, yourCar;

    //访问结构成员时，在对象名称后面使用一个点号
    myCar.maker = "Mercedes";//I wish
    myCar.year = 2005;
    myCar.price = 45567.75;
    //一个结构蓝图可以生成任意数量的对象，甚至还可以生成对象数组：
    //CarType dealerCar[100];
    //修改索引10处的成员year为2004：
    //dealerCar[10] = 2004;

    //myCar.engine.numCylinders = 6;
    //myCar.wheel[2] = "Goodyear";

    //结构的对象可以赋值给同一结构的另一个对象(属于同一结构的对象之间)
    //yourCar = myCar;

    getYourCar(yourCar);

    cout<<"Your car is a:"<<yourCar.maker<<endl;
    cout<<fixed<<showpoint<<setprecision(2)<<"I'll offer $"<<yourCar.price-100<<" for your car."<<endl;

    return 0;
}

//结构的对象可以传递给另一个函数，这里按传址方式传递
//该函数中car对象的所有改变都将映射到main函数的yourCar对象上
void getYourCar(CarType & car)
{
    cout<<"Enter your maker:";
    cin>>car.maker;
    cout<<"Enter the year:";
    cin>>car.year;
    cout<<"Enter the price:$";
    cin>>car.price;
}