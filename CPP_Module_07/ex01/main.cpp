#include <iostream>
#include "iter.hpp"

void printInt(int x)
{
    std::cout << x << " ";
}

void printString(const std::string& str)
{
    std::cout << str << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"hello", "world", "template"};

    std::cout << "Int array: ";
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArr, 3, printString);
    std::cout << std::endl;

    return 0;
}
