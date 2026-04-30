#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Jefe", 1);
    Intern someRandomIntern;

    std::cout << "--- PRUEBA 1: Intern crea ShrubberyCreationForm ---" << std::endl;
    try
    {
        AForm *form = someRandomIntern.makeForm("shrubbery creation", "garden");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 2: Intern crea RobotomyRequestForm ---" << std::endl;
    try
    {
        AForm *form = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 3: Intern crea PresidentialPardonForm ---" << std::endl;
    try
    {
        AForm *form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 4: Nombre de form inexistente ---" << std::endl;
    try
    {
        AForm *form = someRandomIntern.makeForm("nuclear strike", "Earth");
        if (form)
            delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 5: Mayúsculas (debe fallar, distinción case-sensitive) ---" << std::endl;
    try
    {
        AForm *form = someRandomIntern.makeForm("Robotomy Request", "TestSubject");
        if (form)
            delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
