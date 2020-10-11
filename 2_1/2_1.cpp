// 2_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct CarType
{
	string maker;
	int year;
	float price;
	bool operator >(int num) { if (price > num) return true; return false; }
};

int main()
{
    cout << "Hello World!\n"; 
	CarType myCar;

	myCar.maker = "Mercedes";
	myCar.year = 2016;
	myCar.price = 45567.75;

	if (myCar > 2000)
	{
		cout << "My car is more than 2000!" << endl;
	}

	/*int num[5];
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter element" << i << ":";
		cin >> num[i];
	}

	for (int i = 0; i < 5; i++)
	{
		sum += i[num];
	}

	cout << "The sum is:" << sum << endl;*/
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
