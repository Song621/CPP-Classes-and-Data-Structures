#include <iostream>
#include <iomanip>
#include <string>
#include "checkbook.cpp"//编译类模板的两种方式 https://www.cnblogs.com/xiximayou/p/12107823.html  https://www.zhihu.com/question/20630104

using namespace std;
//二元重载运算符函数，两个操作数必须有一个是对象。如果左边的操作数是结构的对象，那么整个函数定义通常位于结构定义内部。
struct MyCheck
{
	float amt{};
	int checkNum{};
	string checkComment;//字符串实际上就是类，是一种抽象数据类型（abstract data type, ADT)，不仅拥有数据，还拥有函数。
	bool operator >(float bal) { if (amt > bal) return true; return false; }
};
//当左操作数不是对象，而右操作数是对象时，最好将函数定义直接放在结构定义的下方
void operator -=(float& bal, MyCheck ch) { bal -= ch.amt; }

int main()
{
	Checkbook<float> johnsCheckbook;
	Checkbook<MyCheck> susansCheckbook;

	MyCheck susansCheck;
	float amount;
	bool johnsCheckAccepted = false, susansCheckAccepted = false;

	johnsCheckbook.setBalance(1000);
	susansCheckbook.setBalance(2000);

	cout << "John, your balance is $1000.00." << endl;
	cout << "Susan, your balance is $2000.00." << endl;

	cout << "John, enter your check amount: $";
	cin >> amount;
	if (johnsCheckbook.writeCheck(amount))
	{
		cout << "Your check was accepted." << endl;
		johnsCheckAccepted = true;
	}
	else
		cout << "Your balance was not high enough to cover the check." << endl;

	cout << "Susan, enter the check number for your check: ";
	cin >> susansCheck.checkNum;
	cin.ignore();
	cout << "Please also enter any comment you wish to make about the check:" << endl;
	getline(cin, susansCheck.checkComment);
	cout << "Susan, enter your check amount: $";
	cin >> susansCheck.amt;
	if (susansCheckbook.writeCheck(susansCheck))
	{
		cout << "Your check was accepted." << endl;
		susansCheckAccepted = true;
	}
	else
		cout << "Your balance was not high enough to cover the check." << endl;

	cout << fixed << showpoint << setprecision(2);
	cout << "John, your balance is: $" << johnsCheckbook.getBalance() << endl;
	if (johnsCheckAccepted)
	{
		cout << "Your last check amount is: $" << johnsCheckbook.getLastCheck() << endl;
	}

	cout << "Susan, your balance is: $" << susansCheckbook.getBalance() << endl;
	if (susansCheckAccepted)
	{
		cout << "Your last check amount is: $" << susansCheckbook.getLastCheck().amt << endl;
		cout << "for check number: " << susansCheckbook.getLastCheck().checkNum << endl;
		cout << "with check comment: " << susansCheckbook.getLastCheck().checkComment << endl;
	}

	return 0;
}