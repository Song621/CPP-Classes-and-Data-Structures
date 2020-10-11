#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


struct CarType{
    //结构的元素称为数据成员
    string maker;
    int year;
    float price;
    bool operator >(float num){if(price>num) return true; return false;}
    //bool operator >(int num){if(year>num) return true; return false;}
    bool operator >(CarType car){if(price>car.price) return true; return false;}
    float operator +(CarType car){return price + car.price;}
};
bool operator <(float num,CarType car)
{
    if (num < car.price)
        return true;
    return false;
        
    
}

int main()
{
    CarType myCar, yourCar;
    float totalPrice;

    myCar.maker = "Mercedes";//I wish
    myCar.year = 2005;
    myCar.price = 45567.75;

    yourCar.maker = "BMW";//I wish
    yourCar.year = 2005;
    yourCar.price = 39999.75;

    /*if (myCar>2000)
    {
        cout<<"My car is older than 2000!"<<endl;
    }*/
    if (myCar>2000.0)
    {
        cout<<"My car is more than 2000!"<<endl;
    }

    if (myCar > yourCar)
    {
        cout<<"My car is greater than your car!"<<endl;
    }
    
    totalPrice = myCar + yourCar;
    cout<<"totalPrice:$ "<<totalPrice<<endl;
    
    if (2000 < myCar)
    {
        cout<<"My car is Greater than 2000!"<<endl;
    }
    else{
        cout<<"My car is Cheaper than 2000!"<<endl;
    }
    

    return 0;
}
