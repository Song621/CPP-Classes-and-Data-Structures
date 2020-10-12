#include <iostream>
#include "queue.h"

using namespace std;
int main()
{
    Queue<int> que;
    int temp;

    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    //que.enqueue(4);

    cout<<"isEmpty: "<<que.isEmpty()<<endl;

    que.dequeue(temp);
    cout<<"deqElement: "<<temp<<endl;

    que.peek(temp);
    cout<<"frontElement: "<<temp<<endl;

    que.makeEmpty();

    return 0;
}