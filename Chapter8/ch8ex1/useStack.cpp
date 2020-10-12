#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> numstack;
    int temp;

    numstack.push(1);
    numstack.push(2);
    numstack.push(3);

	numstack.peek(temp);
    cout<<"top element: "<<temp<<endl;
    numstack.pop(temp);
    cout<<"popedElement: "<<temp<<endl;

	numstack.peek(temp);
    cout<<"top element: "<<temp<<endl;
    numstack.pop(temp);
    cout<<"popedElement: "<<temp<<endl;

    return 0;
}