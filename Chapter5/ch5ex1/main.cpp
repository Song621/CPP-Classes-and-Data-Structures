#include <iostream>
#define DEBUG_ARRAY
#include "Array.h"

using namespace std;

void getElements(Array<int> &numbers);
float clacAverage(Array<int> avnums);

int main()
{
    Array<int> nums(2);
    getElements(nums);
    float average = clacAverage(nums);

    cout<<"The average is:"<<average<<endl;

    return 0;
}

void getElements(Array<int> &numbers)
{
    int i = 0;
    cout<<"Enter a positive integer:";
    cin>>numbers[i];
	while (numbers[i] != -1)
	{
		i++;
		if (i == numbers.length())
		{
			numbers.changeSize(i * 2);
		}
        cout<<"Enter a positive integer (Enter -1 to stop):";
        cin>>numbers[i];
	}
    numbers.changeSize(i);
	cout << "getElements:" << numbers.err();
}

float clacAverage(Array<int> avnums)
{
	int sum = 0;
	for (int i = 0; i < avnums.length(); i++)
	{
		sum += avnums[i];
	}
	cout << "clacAverage:" << avnums.err();
	return sum / float(avnums.length());
}