#include <iostream>
#include <iomanip>
#include <string>
#include "checkbook.h"

using namespace std;

int menu();

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, QUIT = 4;

int main()
{
	float balance;
	cout<<"Enter the initial balance:$ ";
	cin>>balance;

    Checkbook<float> cb(balance);
    float amount;
    int choice;
	bool checkAccepted = false;

    cout<<fixed<<showpoint<<setprecision(2);
    choice = menu();

    while (choice != QUIT)
    {
        if (choice == CHECK)
        {
            cout<<"Enter chenck amount:$";
            cin>>amount;
            //有些程序员在writeCheck中向用户显示消息，若这样做，必须在类实现文件的顶部包含iostream文件，
            //这样才能在类函数中使用cout
            //但这种方法整个都是错的
            if (cb.writeCheck(amount))
			{
                cout<<"Chenck accepted."<<endl;
				checkAccepted = true;
			}
            else{
                cout<<"Your balance is not high enough for that check."<<endl;
            }
        }
        else if(choice == DEPOSIT){
            cout<<"Enter deposit amount:$";
            cin>>amount;
            cb.deposit(amount);
            cout<<"Deposit accepted."<<endl;
        }
        else{
            amount = cb.getBalance();
            cout<<"Your balance is:$"<<amount<<endl;
        }
        choice = menu();
		
    }

	if (checkAccepted)
	{
		cout<<"Your last check was:$"<<cb.getLastCheck()<<endl;
		CheckInfo<float> ci;
		ci = cb.getLastChecks();
		if(ci.numChecks > 1)
		{
			cout<<"Your last checks are:"<<endl;
			for (int i = 0; i < ci.numChecks; i++)
			{
				cout<<"$"<<ci.checks[i]<<endl;
			}
			
		}
	}
    return 0;
}

int menu()
{
    int choice;
    
    cout<<endl;
    cout<<"1 Write a check"<<endl;
    cout<<"2 Make a deposit"<<endl;
    cout<<"3 Get the balance"<<endl;
    cout<<"4 Quit"<<endl;
    cout<<"Enter a number between 1 and 4: ";
    cin>>choice;

    return choice;
}
