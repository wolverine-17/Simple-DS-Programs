#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert an infix expression to postfix
string infixToPostfix(const string &infix)
{
    stack<char> operatorStack;
    string postfix;
    int n = infix.length();

    for (int i = 0; i < n; i++)
    {
        char currentChar = infix[i];

        if (isalnum(currentChar))
        {
            postfix += currentChar;
        }
        else if (currentChar == '(')
        {
            operatorStack.push(currentChar);
        }
        else if (currentChar == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the '('
        }
        else if (isOperator(currentChar))
        {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(currentChar))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }

    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix)
{
    stack<int> operandStack;
    int n = postfix.length();

    for (int i = 0; i < n; i++)
    {
        char currentChar = postfix[i];

        if (isdigit(currentChar))
        {
            operandStack.push(currentChar - '0');
        }
        else if (isOperator(currentChar))
        {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (currentChar)
            {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            }
        }
    }

    return operandStack.top();
}

int main()
{
    string infixExpression, postfixExpression;

    // Input an infix expression
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix
    postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result after evaluation: " << result << endl;

    return 0;
}
