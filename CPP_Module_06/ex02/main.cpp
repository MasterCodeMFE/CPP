#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void printHeader(const std::string& title)
{
    std::cout << BOLD << CYAN << "\n========================================\n"
              << title
              << "\n========================================\n" << RESET;
}

int main()
{
    std::srand(std::time(0));

    printHeader("TEST 1: Identification of Manually Created Objects");

    Base* a = new A;
    Base* b = new B;
    Base* c = new C;

    std::cout << GREEN << "[🔍 Identification with pointer]" << RESET << std::endl;
    std::cout << "  → " << YELLOW << "Object A: " << RESET; identify(a);
    std::cout << "  → " << YELLOW << "Object B: " << RESET; identify(b);
    std::cout << "  → " << YELLOW << "Object C: " << RESET; identify(c);

    std::cout << GREEN << "\n[🔍 Identification with reference]" << RESET << std::endl;
    std::cout << "  → " << YELLOW << "Object A: " << RESET; identify(*a);
    std::cout << "  → " << YELLOW << "Object B: " << RESET; identify(*b);
    std::cout << "  → " << YELLOW << "Object C: " << RESET; identify(*c);

    delete a;
    delete b;
    delete c;

    printHeader("TEST 2: Identification of Randomly Generated Objects");

    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        
        std::cout << BLUE << "🆕 Object " << i + 1 << " generated: " << RESET << std::endl;
        
        if (obj)
        { 
            std::cout << GREEN << "  [🔍 Identification with pointer]: " << RESET;
            identify(obj);

            std::cout << GREEN << "  [🔍 Identification with reference]: " << RESET;
            identify(*obj);
        }

        delete obj;
    }

    printHeader("🟢 TESTS COMPLETED 🟢");
    return 0;
}