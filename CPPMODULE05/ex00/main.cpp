#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- PRUEBA 1: Creación válida ---" << std::endl;
    try
    {
        Bureaucrat boss("Jefe", 1);
        std::cout << boss << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 2: Increment / Decrement válidos ---" << std::endl;
    try
    {
        Bureaucrat mid("Oficinista", 70);
        std::cout << mid << std::endl;
        mid.incrementGrade();
        std::cout << "Tras incrementar: " << mid << std::endl;
        mid.decrementGrade();
        std::cout << "Tras decrementar: " << mid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 3: Grade demasiado alto al construir (0) ---" << std::endl;
    try
    {
        Bureaucrat tooHigh("Imposible", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 4: Grade demasiado bajo al construir (151) ---" << std::endl;
    try
    {
        Bureaucrat tooLow("Imposible", 151);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 5: Increment desde grade 1 (overflow) ---" << std::endl;
    try
    {
        Bureaucrat top("Jefe", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
        std::cout << top << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- PRUEBA 6: Decrement desde grade 150 (underflow) ---" << std::endl;
    try
    {
        Bureaucrat bottom("Becario", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << bottom << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
