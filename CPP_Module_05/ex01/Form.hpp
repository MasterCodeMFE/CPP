#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        int gradeToSign;
        const int execGrade;

    public:
        Form();
        Form(const std::string name, int gradeToSign, const int execGrade);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        class GradeTooHighException : public std::exception
        {
            const char * what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            const char * what() const throw();
        };

        std::string getName() const;
        bool getIsSigned() const;
        int  getGradeToSign() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif