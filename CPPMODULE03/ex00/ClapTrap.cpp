
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void)
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << CYAN << "ClapTrap " << this->_name << " constructed!" << RESET
            << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << CYAN << "ClapTrap " << this->_name << " constructed!" << RESET
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  *this = copy;
  std::cout << CYAN << "ClapTrap copy constructor called" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  std::cout << CYAN << "ClapTrap copy assignment operator called" << RESET
            << std::endl;
  return *this;
}

ClapTrap::~ClapTrap(void) {
  std::cout << RED << "ClapTrap " << this->_name << " destroyed." << RESET
            << std::endl;
}


void ClapTrap::attack(const std::string &target) {
  if (this->_energyPoints > 0 && this->_hitPoints > 0) 
  {
    std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!"
              << RESET << std::endl;
    this->_energyPoints--;
  } 
  else 
  {
    std::cout << "ClapTrap " << this->_name
              << " can't attack! (HP: " << this->_hitPoints
              << ", Energy: " << this->_energyPoints << ")" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) 
    {
        std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= (unsigned int)this->_hitPoints) 
        this->_hitPoints = 0;
    else 
        this->_hitPoints -= amount;

    std::cout << YELLOW << "ClapTrap " << this->_name << " takes " << amount 
              << " damage! HP: " << this->_hitPoints << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energyPoints > 0 && this->_hitPoints > 0) 
  {
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << GREEN << "ClapTrap " << this->_name << " repairs itself for "
              << amount << " points! New HP: " << this->_hitPoints << RESET
              << std::endl;
  } 
  else 
  {
    std::cout << BLUE << "ClapTrap " << this->_name
              << " can't repair! (HP: " << this->_hitPoints
              << ", Energy: " << this->_energyPoints << ")" << RESET
              << std::endl;
  }
}



std::string const &ClapTrap::getName(void) const 
{
  return (this->_name); 
}

int const &ClapTrap::getHitPoints(void) const 
{
  return (this->_hitPoints); 
}

int const &ClapTrap::getEnergyPoints(void) const 
{
  return (this->_energyPoints);
}

int const &ClapTrap::getAttackDamage(void) const {
  return (this->_attackDamage);
}


void ClapTrap::setName(std::string const &name)
{ 
  this->_name = name; 
}

void ClapTrap::setHitPoints(int const &value)
{ 
  this->_hitPoints = value; 
}

void ClapTrap::setEnergyPoints(int const &value)
{ 
  this->_energyPoints = value;
}

void ClapTrap::setAttackDamage(int const &value)
{ 
  this->_attackDamage = value;
}
