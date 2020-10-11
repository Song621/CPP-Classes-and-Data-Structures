#include <iostream>
#include "MinBalCheckBook.h"

using namespace std;
void foo(CheckBook<float> & cbook);

int main()
{
    CheckBook<float> cbook1(500);
    MinBalCheckBook<float> cbook2(1000,200,100,0.5F);


    CheckBook<float> *ptr1 = &cbook2;

    foo(cbook1);
    cout<<cbook1.getBalance()<<endl;
    foo(cbook2);
    cout<<cbook2.getBalance()<<endl;
    foo(*ptr1);
    cout<<ptr1->getBalance()<<endl;

    return 0;
}

void foo(CheckBook<float> & cbook)
{
    cbook.writeCheck(200);
}
