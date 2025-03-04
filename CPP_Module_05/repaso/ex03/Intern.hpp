#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.cpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

        AForm* makeForm(std::string a, std::string b);
}; 

#endif