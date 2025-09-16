#include "RPN.hpp"

// Usar std::stack<double> en una calculadora RPN ofrece:
// - **Acceso restringido**: solo se puede acceder al elemento superior, evitando modificaciones no deseadas.
// - **Interfaz semántica clara**: expresa de forma explícita que se sigue el principio LIFO (Last In, First Out).
// - **Evita errores de acceso**: al no permitir acceso a elementos intermedios, se reduce el riesgo de errores lógicos.
// - **Implementación eficiente**: generalmente respaldado por std::deque, ofreciendo operaciones push/pop en O(1).
// - **Código más legible y mantenible**: facilita la comprensión del flujo de datos y operaciones en la calculadora.
bool evaluateNPR(const std::string& expression, double& result) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && (token[0] == '-' || token[0] == '+')))
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