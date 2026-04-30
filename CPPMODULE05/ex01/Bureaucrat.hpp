#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Form;
class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & other);
		Bureaucrat & operator=(Bureaucrat const & other);
		~Bureaucrat();

		std::string const & getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what() const throw();
	};
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & b);

#endif
