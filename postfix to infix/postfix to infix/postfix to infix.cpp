#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

int performOperation(int op1, int op2, char op)
{
    int ans;
    switch (op) {
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}

int evaluatePostfix(string postfix)
{
    stack<int> s;
    int op1, op2, len, x;
    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            x = postfix[i] - '0';
            s.push(x);
        }
        else if (isOperator(postfix[i])) {
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(performOperation(op1, op2, postfix[i]));
        }
    }
    return s.top();
}

int main()
{
    string postfix;
    cout << "Enter a Postfix Expression: ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Answer = " << result << endl;
    return 0;
}