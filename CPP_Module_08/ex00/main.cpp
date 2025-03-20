#include "easyfind.hpp"

int main()
{
    std::vector<int> numeros;
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);
    numeros.push_back(40);
    numeros.push_back(50);
    numeros.push_back(60);
    numeros.push_back(70);
    numeros.push_back(80);
    numeros.push_back(90);

    easyfind(numeros, 2);
    easyfind(numeros, 40); 
}