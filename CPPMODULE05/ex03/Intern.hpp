#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		AForm* createShrubbery(const std::string &target);
		AForm* createRobotomy(const std::string &target);
		AForm* createPardon(const std::string &target);
};

#endif
