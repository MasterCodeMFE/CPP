#include "easyfind.hpp"

template<typename T>
void easyfind(T& first, int second)
{
    typename T::iterator it = std::find(first.begin(), first.end(), second);

    if (it != first.end())
    {
        std::cout << "Find in the position: " << std::distance(first.begin(), it) << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
}