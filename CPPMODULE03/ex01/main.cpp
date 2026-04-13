#include "ScavTrap.hpp"

int main(void) {
  
    ClapTrap clappy("Clappy");
    ScavTrap trappy("Trappy");
    std::cout << std::endl;

    clappy.attack("a dummy");
    
    trappy.attack("Clappy");
    clappy.takeDamage(trappy.getAttackDamage());
    std::cout << std::endl;

    trappy.guardGate();
    std::cout << std::endl;
    
    trappy.beRepaired(10);
    std::cout << std::endl;

    return (0);
}
