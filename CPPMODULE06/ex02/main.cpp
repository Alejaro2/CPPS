#include "Base.hpp"
#include <iostream>

int main ()
{
    srand(static_cast<unsigned int>(time(NULL)));
    Base *obj = generate();
    std::cout << "Identified by pointer:" << std::endl;
    identify(obj);
    std::cout << "Identified by reference:" << std::endl;
    identify(*obj);
    delete obj;
    return (0);
}