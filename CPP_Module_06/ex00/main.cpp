#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
        ScalarConverter::convert("a");
    else
    {   
        while (argv[i])
        {
            std::string literal = argv[i];
            ScalarConverter::convert(literal);
            i++;
            std::cout << std::endl << std::endl;
        }
    }
    return 0;
}