/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:38:57 by manufern          #+#    #+#             */
/*   Updated: 2024/12/04 17:03:31 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    // Create instances of the fixed class for testing
    fixed a;  // Default constructor, should initialize to zero
    fixed b(5.05f);  // Constructor with a float value
    fixed c(2);  // Constructor with an integer value
    fixed const d(b * c);  // Constant for comparison tests, the result of b multiplied by c

    // Output initial values of fixed instances
    std::cout << "Initial value of 'a' (default initialized): " << a << std::endl;
    std::cout << "Value of 'b' (initialized with 5.05): " << b << std::endl;
    std::cout << "Value of 'c' (initialized with 2): " << c << std::endl;
    std::cout << "Constant value 'd' (result of b * c): " << d << std::endl;

    // Increment and Decrement operations
    std::cout << "\nIncrement and Decrement Operations:" << std::endl;
    std::cout << "Pre-increment of 'a' (++a): " << ++a << " (increments 'a' before displaying its value)" << std::endl;
    std::cout << "Post-increment of 'a' (a++): " << a++ << " (displays current value of 'a' before incrementing)" << std::endl;
    std::cout << "Value of 'a' after post-increment: " << a << " (the value after post-increment operation)" << std::endl;
    std::cout << "Pre-decrement of 'a' (--a): " << --a << " (decrements 'a' before displaying its value)" << std::endl;
    std::cout << "Post-decrement of 'a' (a--): " << a-- << " (displays current value of 'a' before decrementing)" << std::endl;
    std::cout << "Value of 'a' after post-decrement: " << a << " (the value after post-decrement operation)" << std::endl;

    // Comparison operations
    std::cout << "\nComparison Operations:" << std::endl;
    std::cout << "Is 'a' greater than 'b'? (" << a << " > " << b << "): " << (a > b) << " (result is true if 'a' is greater than 'b')" << std::endl;
    std::cout << "Is 'a' less than 'b'? (" << a << " < " << b << "): " << (a < b) << " (result is true if 'a' is less than 'b')" << std::endl;
    std::cout << "Is 'a' greater than or equal to 'b'? (" << a << " >= " << b << "): " << (a >= b) << " (result is true if 'a' is greater than or equal to 'b')" << std::endl;
    std::cout << "Is 'a' less than or equal to 'b'? (" << a << " <= " << b << "): " << (a <= b) << " (result is true if 'a' is less than or equal to 'b')" << std::endl;
    std::cout << "Is 'a' equal to 'b'? (" << a << " == " << b << "): " << (a == b) << " (result is true if 'a' is equal to 'b')" << std::endl;
    std::cout << "Is 'a' not equal to 'b'? (" << a << " != " << b << "): " << (a != b) << " (result is true if 'a' is not equal to 'b')" << std::endl;

    // Arithmetic operations
    std::cout << "\nArithmetic Operations:" << std::endl;
    fixed sum = b + c;  // Sum of b and c
    fixed diff = b - c;  // Difference of b and c
    fixed prod = b * c;  // Product of b and c
    fixed div = b / c;  // Division of b by c
    fixed zero(0);  // Initialize a fixed object with value zero
    fixed divByZero = b / zero;  // Attempting division by zero

    // Output results of arithmetic operations
    std::cout << "Sum (b + c): " << b << " + " << c << " = " << sum << std::endl;
    std::cout << "Difference (b - c): " << b << " - " << c << " = " << diff << std::endl;
    std::cout << "Product (b * c): " << b << " * " << c << " = " << prod << std::endl;
    std::cout << "Division (b / c): " << b << " / " << c << " = " << div << std::endl;

    // Output results for division by zero
    std::cout << "Attempting division by zero (b / 0): " << b << " / " << zero << " = " << divByZero << " (should handle division by zero case gracefully)" << std::endl;
    std::cout << "Attempting division of zero by zero (0 / 0): " << zero << " / " << zero << " = " << divByZero << " (should handle division by zero case gracefully)" << std::endl;

    // Extreme value tests
    std::cout << "\nExtreme Value Tests:" << std::endl;
    fixed largeValue(std::numeric_limits<float>::max());  // Maximum float value
    fixed smallValue(std::numeric_limits<float>::min());  // Minimum positive float value
    fixed negativeLargeValue(-std::numeric_limits<float>::max());  // Negative maximum float value
    fixed negativeSmallValue(-std::numeric_limits<float>::min());  // Negative minimum positive float value

    // Output extreme values
    std::cout << "Large Value (maximum float): " << largeValue << std::endl;
    std::cout << "Small Value (minimum positive float): " << smallValue << std::endl;
    std::cout << "Negative Large Value (negative maximum float): " << negativeLargeValue << std::endl;
    std::cout << "Negative Small Value (negative minimum positive float): " << negativeSmallValue << std::endl;

    // Operations with extreme values
    std::cout << "Adding largeValue and b: " << largeValue << " + " << b << " = " << (largeValue + b) << std::endl;
    std::cout << "Subtracting b from largeValue: " << largeValue << " - " << b << " = " << (largeValue - b) << std::endl;
    std::cout << "Multiplying smallValue with b: " << smallValue << " * " << b << " = " << (smallValue * b) << std::endl;
    std::cout << "Dividing negativeLargeValue by c: " << negativeLargeValue << " / " << c << " = " << (negativeLargeValue / c) << std::endl;

    // Additional extreme value operations
    fixed largeSum = largeValue + negativeLargeValue; // Should be close to zero
    fixed largeProduct = largeValue * smallValue; // Should be a very small number
    fixed largeDivision = largeValue / smallValue; // Should be a very large number

    std::cout << "Sum of largeValue and negativeLargeValue: " << largeValue << " + " << negativeLargeValue << " = " << largeSum << " (expected to be close to zero)" << std::endl;
    std::cout << "Product of largeValue and smallValue: " << largeValue << " * " << smallValue << " = " << largeProduct << " (expected to be a very small number)" << std::endl;
    std::cout << "Division of largeValue by smallValue: " << largeValue << " / " << smallValue << " = " << largeDivision << " (expected to be a very large number)" << std::endl;

    // Use of static min and max functions
    std::cout << "\nStatic min and max Functions:" << std::endl;
    std::cout << "Minimum of 'a' and 'b': fixed::min(a, b) = " << fixed::min(a, b) << " (comparing " << a << " and " << b << ")" << std::endl;
    std::cout << "Maximum of 'a' and 'b': fixed::max(a, b) = " << fixed::max(a, b) << " (comparing " << a << " and " << b << ")" << std::endl;
    std::cout << "Minimum of 'b' and 'd': fixed::min(b, d) = " << fixed::min(b, d) << " (comparing " << b << " and " << d << ")" << std::endl;
    std::cout << "Maximum of 'b' and 'd': fixed::max(b, d) = " << fixed::max(b, d) << " (comparing " << b << " and " << d << ")" << std::endl;

    return 0;
}
