#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Jefe", 1);
    Bureaucrat intern("Becario", 150);
    Bureaucrat mid("Oficinista", 70);

    std::cout << "--- PRUEBA 1: Shrubbery (Niveles: Firma 145, Exec 137) ---" << std::endl;
    ShrubberyCreationForm f1("home");
    
    intern.signForm(f1);
    
    boss.signForm(f1);
    boss.executeForm(f1);

    std::cout << "\n--- PRUEBA 2: Robotomy (Niveles: Firma 72, Exec 45) ---" << std::endl;
    RobotomyRequestForm f2("robot");
    
    mid.signForm(f2);
    mid.executeForm(f2);
    boss.executeForm(f2);

    std::cout << "\n--- PRUEBA 3: Presidential Pardon (Niveles: Firma 25, Exec 5) ---" << std::endl;
    PresidentialPardonForm f3("Criminal");

    boss.signForm(f3);
    boss.executeForm(f3);

    std::cout << "\n--- PRUEBA 4: Intentar ejecutar sin firma ---" << std::endl;
    PresidentialPardonForm f4("Inocente");
    boss.executeForm(f4);

    return 0;
}