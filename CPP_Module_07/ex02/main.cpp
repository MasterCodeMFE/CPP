#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define SIZE 10

void printArray(const Array<int>& arr) {
    for (unsigned int i = 0; i < arr.getSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::srand(std::time(NULL));

    std::cout << "Creating an Array of size " << SIZE << " with random values..." << std::endl;
    Array<int> numbers(SIZE);
    for (unsigned int i = 0; i < SIZE; i++) {
        numbers[i] = std::rand() % 100;
    }
    std::cout << "Original array: ";
    printArray(numbers);

    std::cout << "\nTesting copy constructor..." << std::endl;
    Array<int> copy(numbers);
    std::cout << "Copied array: ";
    printArray(copy);

    std::cout << "\nModifying the original array..." << std::endl;
    numbers[0] = 999;
    std::cout << "Modified original array: ";
    printArray(numbers);
    std::cout << "Copied array after modification of original: ";
    printArray(copy);

    std::cout << "\nTesting assignment operator..." << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned array: ";
    printArray(assigned);

    std::cout << "\nTesting out-of-bounds access..." << std::endl;
    try {
        std::cout << "Trying to access index -1..." << std::endl;
        numbers[-1] = 42;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to access index " << SIZE << "..." << std::endl;
        numbers[SIZE] = 42;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}
