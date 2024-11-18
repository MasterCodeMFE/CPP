/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:38:57 by manufern          #+#    #+#             */
/*   Updated: 2024/11/18 18:12:49 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    // Creación de instancias de Fixed para pruebas
    fixed a;
    fixed b(5.05f);
    fixed c(2);
    fixed const d(b * c);  // Constante para pruebas de comparación

    std::cout << "Valor inicial de 'a': " << a << std::endl;
    std::cout << "Valor de 'b': " << b << std::endl;
    std::cout << "Valor de 'c': " << c << std::endl;
    std::cout << "Valor constante 'd' (b * c): " << d << std::endl;

    // Incremento y Decremento
    std::cout << "\nIncremento y Decremento:" << std::endl;
    std::cout << "++a: " << ++a << " (pre-incremento de 'a', incrementa antes de mostrar el valor)" << std::endl;
    std::cout << "a++: " << a++ << " (post-incremento de 'a', muestra el valor antes de incrementar)" << std::endl;
    std::cout << "a después de a++: " << a << " (valor después del post-incremento)" << std::endl;
    std::cout << "--a: " << --a << " (pre-decremento de 'a', decrementa antes de mostrar el valor)" << std::endl;
    std::cout << "a--: " << a-- << " (post-decremento de 'a', muestra el valor antes de decrementar)" << std::endl;
    std::cout << "a después de a--: " << a << " (valor después del post-decremento)" << std::endl;

    // Comparaciones
    std::cout << "\nComparaciones:" << std::endl;
    std::cout << "¿a > b? (" << a << " > " << b << "): " << (a > b) << std::endl;
    std::cout << "¿a < b? (" << a << " < " << b << "): " << (a < b) << std::endl;
    std::cout << "¿a >= b? (" << a << " >= " << b << "): " << (a >= b) << std::endl;
    std::cout << "¿a <= b? (" << a << " <= " << b << "): " << (a <= b) << std::endl;
    std::cout << "¿a == b? (" << a << " == " << b << "): " << (a == b) << std::endl;
    std::cout << "¿a != b? (" << a << " != " << b << "): " << (a != b) << std::endl;

    // Operadores aritméticos
    std::cout << "\nOperadores aritméticos:" << std::endl;
    fixed sum = b + c;
    fixed diff = b - c;
    fixed prod = b * c;
    fixed div = b / c;

    std::cout << "b + c = " << b << " + " << c << " = " << sum << std::endl;
    std::cout << "b - c = " << b << " - " << c << " = " << diff << std::endl;
    std::cout << "b * c = " << b << " * " << c << " = " << prod << std::endl;
    std::cout << "b / c = " << b << " / " << c << " = " << div << std::endl;

    // Uso de funciones estáticas min y max
    std::cout << "\nFunciones min y max:" << std::endl;
    std::cout << "fixed::min(a, b): " << fixed::min(a, b) << " (comparando " << a << " y " << b << ")" << std::endl;
    std::cout << "fixed::max(a, b): " << fixed::max(a, b) << " (comparando " << a << " y " << b << ")" << std::endl;
    std::cout << "fixed::min(b, d): " << fixed::min(b, d) << " (comparando " << b << " y " << d << ")" << std::endl;
    std::cout << "fixed::max(b, d): " << fixed::max(b, d) << " (comparando " << b << " y " << d << ")" << std::endl;

    return 0;
}