
#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", false, 72, 45), target(target)
{
    std::cout << "Robotomy default constructor called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return(target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
    {
        std::cout << executor.getName() << " cannot execute " << getName()
                  << " because the form is not signed." << std::endl;
        return;
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowExceptionExecurtor();
    }

    std::cout << "BZZZT! VRRRR! KRKKK!" << std::endl;

    std::srand(static_cast<unsigned int>(std::time(0))); 

    if (std::rand() % 2 == 0)
    {
        std::cout << getTarget() << " has been successfully robotomized." << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << getTarget() << " has failed." << std::endl;
    }
}