#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default") 
{
  std::cout << GREEN << "AAnimal " << _type << " has been constructed!" << RESET
            << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) 
{
  std::cout << GREEN << "AAnimal " << _type << " has been constructed!" << RESET
            << std::endl;
}
AAnimal::AAnimal(const AAnimal &cpy) 
{
  std::cout << GREEN << "AAnimal " << _type << " has been copied!" << RESET
            << std::endl;
  *this = cpy;
}

AAnimal &AAnimal::operator=(const AAnimal &cpy) 
{
  std::cout << GREEN << "AAnimal " << _type << " has been assigned!" << RESET
            << std::endl;
  if (this != &cpy) {
    this->_type = cpy._type;
  }
  return *this;
}

AAnimal::~AAnimal() 
{
  std::cout << RED << "AAnimal " << _type << " has been destroyed!" << RESET
            << std::endl;
}

std::string AAnimal::getType() const 
{
  return this->_type;
}
