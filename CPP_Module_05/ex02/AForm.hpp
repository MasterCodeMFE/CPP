#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        int gradeToSign;
        const int execGrade;

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, const int execGrade);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

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

        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif