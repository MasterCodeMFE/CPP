/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:04 by manufern          #+#    #+#             */
/*   Updated: 2025/01/21 12:55:18 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;
    public:
        AForm(std::string const name, bool isSigned, int const gradeToSign, int const gradeToExecute);
        ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat bureaucrat);

        class GradeTooHighException: public std::exception
        {
          public:
            const char* what() const  throw();
        };

        class GradeTooLowException: public std::exception
        {
          public:
            const char* what() const  throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif