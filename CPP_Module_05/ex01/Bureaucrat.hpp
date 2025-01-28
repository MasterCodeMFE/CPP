#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        const std::string getName() const;
        int  getGrade() const;

        void setIncrement();
        void setDecrement();

        class GradeTooHighException : public std::exception
        {
            const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char * what() const throw();
        };

        void signForm(Form& form);
        
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP