
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");

    clappy.attack("Trappy");
    trappy.takeDamage(0);

    clappy.beRepaired(80);

    while (clappy.getEnergyPoints() > 0)
    {
        clappy.attack("other robot");
    }

    clappy.attack("Trappy");
    clappy.beRepaired(1);

    trappy.takeDamage(20);
    trappy.beRepaired(10);
    trappy.attack("Clappy");

    return (0);
}
