#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        Form();
        Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const  throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const  throw();
        };

        void beSigned(const Bureaucrat& bureaucrat);

};
std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif