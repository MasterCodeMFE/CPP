#include "Span.hpp"

void simpleTest()
{
    std::cout << "===== SIMPLE TEST =====" << std::endl;
    Span sp(5);
    
    sp.addNumber(10);
    sp.addNumber(5);
    
    sp.shortestSpan();
    sp.longestSpan();
    std::cout << std::endl;
}

void bulkInsertTest()
{
    std::cout << "===== BULK INSERT TEST =====" << std::endl;
    Span sp(10);
    
    std::vector<int> values;
    values.push_back(30);
    values.push_back(10);
    values.push_back(50);
    values.push_back(20);
    values.push_back(40);
    sp.addNumbers(values.begin(), values.end());

    sp.shortestSpan();
    sp.longestSpan();
    std::cout << std::endl;
}

void fullCapacityTest()
{
    std::cout << "===== FULL CAPACITY TEST =====" << std::endl;
    Span sp(5);

    try
    {
        sp.addNumber(100);
        sp.addNumber(50);
        sp.addNumber(25);
        sp.addNumber(75);
        sp.addNumber(10);
        
        sp.addNumber(200);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    sp.shortestSpan();
    sp.longestSpan();
    std::cout << std::endl;
}

void largeSpanTest()
{
    std::cout << "===== LARGE SPAN TEST =====" << std::endl;
    Span sp(10000);

    for (int i = 0; i < 10000; i++)
    {
        sp.addNumber(i * 2);
    }

    sp.shortestSpan();
    sp.longestSpan();
    std::cout << std::endl;
}

int main()
{
    simpleTest();
    bulkInsertTest();
    fullCapacityTest();
    largeSpanTest();

    return 0;
}