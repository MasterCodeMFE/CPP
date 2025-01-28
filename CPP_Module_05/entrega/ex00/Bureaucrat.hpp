/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:32:04 by manuel            #+#    #+#             */
/*   Updated: 2025/01/17 11:45:44 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

        void gradeOk(int grade);

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName()const;
        int getGrade()const;
        void incrementGrade();
        void decrementGrade();

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
