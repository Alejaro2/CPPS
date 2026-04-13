
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() 
{
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << CYAN << "FragTrap from ClapTrap " << this->_name << " created"
            << RESET << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << CYAN << "FragTrap from ClapTrap " << this->_name << " created"
            << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
  std::cout << CYAN << "FragTrap from ClapTrap " << this->_name << " copied"
            << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
  std::cout << "Assignment operator for FragTrap called" << std::endl;
  if (this != &copy)
    ClapTrap::operator=(copy);
  return *this;
}

FragTrap::~FragTrap(void) {
  std::cout << RED << "FragTrap " << this->_name << " destroyed" << RESET
            << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << GREEN << "FragTrap " << this->_name
            << " requests a positive high five! ✋" << RESET << std::endl;
}
