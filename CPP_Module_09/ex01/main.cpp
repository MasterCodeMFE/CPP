#include "RPN.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr << "Error: You must provide an expression in Reverse Polish Notation." << std::endl;
        std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
        return 1;
    }
    else
    {
        double result;
        std::string expression = argv[1];
        if (evaluateNPR(expression, result))
        {
            std::cout << result << std::endl;
        }
        else
        {
            std::cerr << "Error" << std::endl;
        }
    }
}