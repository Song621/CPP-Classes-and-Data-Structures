#include "LinkedList.h"
#include <string>
using namespace std;

struct N {
	string info;
	int rank{};
	bool operator == (const N &n) {
		if (rank == n.rank) return true; return false;
	}
};

int main()
{
	N a, b, c, d;
	a.info = "Apple"; a.rank = 1;
	b.info = "Banana"; b.rank = 2;
	c.info = "cat"; c.rank = 3;
	d.info = "dog"; d.rank = 4;

	N temp, goal, newElement;
	LinkedList<N> objects;

	objects.insert(a);
	objects.insert(b);
	objects.insert(c);
	objects.insert(d);

	temp.rank = 2;
	goal.rank = 3;
	newElement.rank = 3; newElement.info = "car";
	objects.retrieve(temp);
	cout << temp.info << endl;

	objects.first(temp);
	cout << "first: " << temp.info << endl;

	objects.retrieve(goal);
	cout << goal.info << endl;
	objects.replace(newElement);
	objects.retrieve(goal);
	cout << "repalced: " << goal.info << endl;

	objects.first(temp);
	cout << temp.rank << "->" << temp.info << endl;
	while (objects.getNext(temp)) {
		cout << temp.rank << "->" << temp.info << endl;
	}
	return 0;
}
int main01()
{
	/*N *a = new N;
	(*a).info = 10;
	if (a->info == 10)
		cout << "YES" << endl;*/
    LinkedList<int> list;
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        list.insert(i);
    }

	cout << "first: " << list.first(temp) << endl;
	cout<<"--" << temp << endl;
	cout << "getNext: " << list.getNext(temp) << endl;
	cout<<"--" << temp << endl;
    cout<<"find: "<<list.find(5)<<endl;
	cout << "getNext: " << list.getNext(temp) << endl;
	cout<<"--" << temp << endl;
	//list.remove(5);
    cout<<"remove: "<<list.remove(temp)<<endl;

	cout << "first: " << list.first(temp) << endl;
	cout<<"--" << temp << endl;
    while(list.getNext(temp)){
        cout<<temp<<"****"<<endl;
    }
    
    return 0;
}