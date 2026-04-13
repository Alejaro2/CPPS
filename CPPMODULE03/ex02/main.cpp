#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
  ClapTrap clappy("Clappy");
  ScavTrap scavvy("Scavvy");
  FragTrap fraggy("Fraggy");
  std::cout << std::endl;

  clappy.attack("a dummy");
  scavvy.attack("a dummy");
  fraggy.attack("a dummy");
  std::cout << std::endl;

  fraggy.highFivesGuys();
  scavvy.guardGate();
  std::cout << std::endl;

  fraggy.takeDamage(50);
  fraggy.beRepaired(20);
  std::cout << std::endl;

  return (0);
}
