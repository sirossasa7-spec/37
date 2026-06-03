#include "PostfixCalculator.h"
#include "MyStack.h"

#include <sstream>
#include <string>

int PostfixCalculator::calculate(const std::string& expression)
{
    MyStack<int> stack;

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isdigit(token[0]) ||
            (token.length() > 1 && token[0] == '-'))
        {
            stack.push(std::stoi(token));
        }
        else
        {
            int b = stack.top();
            stack.pop();

            int a = stack.top();
            stack.pop();

            switch (token[0])
            {
            case '+':
                stack.push(a + b);
                break;

            case '-':
                stack.push(a - b);
                break;

            case '*':
                stack.push(a * b);
                break;

            case '/':
                stack.push(a / b);
                break;
            }
        }
    }

    return stack.top();
}