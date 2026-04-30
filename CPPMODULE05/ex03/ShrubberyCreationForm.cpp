#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* ShrubberyCreationForm::FileOpeningException::what() const throw()
{
    return "ShrubberyCreationForm: Error opening file";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);

	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		throw FileOpeningException();
	}
	file << "       _-_       \n";
	file << "    /~~   ~~\\    \n";
	file << " /~~         ~~\\ \n";
	file << "{               }\n";
	file << " \\  _-     -_  / \n";
	file << "   ~  \\\\ //  ~   \n";
	file << " _- -~  ~-_      \n";
	file << "    ~  \\\\  ~     \n";
	file << "       ||        \n";
	file << "       ||        \n";
	file << "      /__\\       \n";
	file.close();
}
