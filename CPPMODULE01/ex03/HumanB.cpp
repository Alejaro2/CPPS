#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
  this->_name = name;
  this->_weapon = NULL;
  std::cout << this->_name << " created with no weapon" << std::endl;
}

HumanB::~HumanB(void) { 
  std::cout << this->_name << " destroyed" << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon) { 
  this->_weapon = &weapon; 
}

void HumanB::attack(void) {
  if (this->_weapon)
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
  else
    std::cout << this->_name << " has no weapon" << std::endl;
}
