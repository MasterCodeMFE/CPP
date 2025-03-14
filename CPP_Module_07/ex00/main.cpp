#include "whatever.hpp"
#include <string>
#include <iostream>

/* void printLine() {
    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    int a = 10, b = 20;
    double x = 5.5, y = 2.2;
    std::string str1 = "Hello", str2 = "World";

    printLine();
    std::cout << "🔄 SWAP TEST" << std::endl;
    printLine();
    std::cout << "Antes de swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "Después de swap: a = " << a << ", b = " << b << std::endl;

    printLine();
    std::cout << "📉 MIN & 📈 MAX TEST (INT)" << std::endl;
    printLine();
    std::cout << "Min(" << a << ", " << b << "): " << ::min(a, b) << std::endl;
    std::cout << "Max(" << a << ", " << b << "): " << ::max(a, b) << std::endl;

    printLine();
    std::cout << "📉 MIN & 📈 MAX TEST (DOUBLE)" << std::endl;
    printLine();
    std::cout << "Min(" << x << ", " << y << "): " << ::min(x, y) << std::endl;
    std::cout << "Max(" << x << ", " << y << "): " << ::max(x, y) << std::endl;

    printLine();
    std::cout << "🔠 STRING COMPARISON TEST" << std::endl;
    printLine();
    std::cout << "Min(\"" << str1 << "\", \"" << str2 << "\"): " << ::min(str1, str2) << std::endl;
    std::cout << "Max(\"" << str1 << "\", \"" << str2 << "\"): " << ::max(str1, str2) << std::endl;

    printLine();
    std::cout << "✅ PRUEBA FINALIZADA ✅" << std::endl;
    printLine();

    return 0;
} */


int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b ); // se pone ::swap para segurarse de que estas llamando a tus funciones no a otras que esten en otra librería
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}
