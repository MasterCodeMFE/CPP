#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <iomanip>

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

        
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP