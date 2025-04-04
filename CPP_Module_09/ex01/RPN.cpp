#include "RPN.hpp"

bool evaluateNPR(const std::string& expression, double& result) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            std::istringstream numStream(token);
            double number;
            numStream >> number;
            if (number >= 10)
            {
                return false;
            }
            stack.push(number);
        }
        else
        {
            if (stack.size() < 2)
            {
                return false;
            }
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            switch (token[0])
            {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/':
                    if (b == 0)
                    {
                        return false;
                    }
                    stack.push(a / b); 
                    break;
                default:
                    return false;
            }
        }
    }
    if (stack.size() != 1)
    {
        return false;
    }

    result = stack.top();
    return true;
}