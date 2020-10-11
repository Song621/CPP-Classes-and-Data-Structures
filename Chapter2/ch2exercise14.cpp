//求后缀表达式的值
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solvePostfixExpression(string formula);

int main()
{
    string formula = "34*873-//4+";

    cout<<formula.size()<<endl;
    cout<<"The result of the postfix expression is "<<solvePostfixExpression(formula)<<endl;

    return 0;
}

int solvePostfixExpression(string formula)
{
    stack<int> operand;
    int operand1, operand2;
    int temp;
    for (int i = 0; i < formula.size(); i++)
    {
        if (formula[i]!='+' && formula[i]!='-' &&formula[i]!='*' && formula[i]!='/')
        {
            operand.push(formula[i]);
            //cout<<"%%%%%"<<formula[i] - '0'<<endl;
        }
        else
        {
            operand2 = operand.top();//top函数的返回值是栈顶元素（注意并没有删掉栈顶元素）
            operand.pop();//pop函数将栈顶元素删掉，没有返回值
            if (operand2 == '0' && formula[i] == '/')
            {
                cout<<"Error: Division by zero!"<<endl;
                break;
            }
            operand1 = operand.top();
            operand.pop();
            if(formula[i]=='+') temp = (operand1-'0') + (operand2-'0');//char转int
            else if(formula[i]=='-') temp = (operand1-'0') - (operand2-'0');
            else if(formula[i]=='*') temp = (operand1-'0') * (operand2-'0');
            else temp = (operand1-'0') / (operand2-'0');
            //cout<<"A: "<<operand1 - '0'<<endl;
            //cout<<"B: "<<operand2 - '0'<<endl;
            cout<<operand1-'0'<<formula[i]<<operand2-'0'<<'='<<temp<<endl;
            operand.push(temp+'0');//int转char
        }
    }
    return operand.top()-'0';
}
