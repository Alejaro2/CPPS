
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(void) : ClapTrap() 
{
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap from claptrap" << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap from claptrap " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap from claptrap " << _name << " copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "Assignment operator for scavtrap called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (this->_energyPoints > 0 && this->_hitPoints > 0) {
    std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!"
              << RESET << std::endl;
    this->_energyPoints--;
  } else {
    std::cout << "ScavTrap " << this->_name
              << " can't attack! (HP: " << this->_hitPoints
              << ", Energy: " << this->_energyPoints << ")" << std::endl;
  }
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode."
            << std::endl;
}
