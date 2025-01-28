/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:04 by manufern          #+#    #+#             */
/*   Updated: 2025/01/20 16:18:27 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;
    public:
        Form(std::string const name, bool isSigned, int const gradeToSign, int const gradeToExecute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

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

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif