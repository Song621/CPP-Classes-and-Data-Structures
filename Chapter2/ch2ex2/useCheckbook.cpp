#include <iostream>
#include <iomanip>
#include <string>
#include "checkbook.cpp"//������ģ������ַ�ʽ https://www.cnblogs.com/xiximayou/p/12107823.html  https://www.zhihu.com/question/20630104

using namespace std;
//��Ԫ�������������������������������һ���Ƕ��������ߵĲ������ǽṹ�Ķ�����ô������������ͨ��λ�ڽṹ�����ڲ���
struct MyCheck
{
	float amt{};
	int checkNum{};
	string checkComment;//�ַ���ʵ���Ͼ����࣬��һ�ֳ����������ͣ�abstract data type, ADT)������ӵ�����ݣ���ӵ�к�����
	bool operator >(float bal) { if (amt > bal) return true; return false; }
};
//������������Ƕ��󣬶��Ҳ������Ƕ���ʱ����ý���������ֱ�ӷ��ڽṹ������·�
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