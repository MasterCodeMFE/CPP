#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif