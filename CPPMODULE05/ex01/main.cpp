#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Jefe", 1);
    Bureaucrat intern("Becario", 150);
    Bureaucrat mid("Oficinista", 70);

    std::cout << "--- PRUEBA 1: Firma exitosa (Niveles: Firma 50, Exec 25) ---" << std::endl;
    Form f1("Form1", 50, 25);
    std::cout << f1 << std::endl;
    boss.signForm(f1);
    std::cout << f1 << std::endl;

    std::cout << "\n--- PRUEBA 2: Firma denegada (grade insuficiente) ---" << std::endl;
    Form f2("Form2", 100, 50);
    intern.signForm(f2);

    std::cout << "\n--- PRUEBA 3: Form con gradeToSign inválido (0) ---" << std::endl;
    try
    {
        Form f3("Form3", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 4: Form con gradeToExecute inválido (151) ---" << std::endl;
    try
    {
        Form f4("Form4", 50, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 5: Firma en el límite (Oficinista grade 70 firma form gradeToSign 70) ---" << std::endl;
    Form f5("Form5", 70, 20);
    mid.signForm(f5);
    std::cout << f5 << std::endl;

    return 0;
}
