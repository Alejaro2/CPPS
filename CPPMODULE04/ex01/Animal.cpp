#include "Animal.hpp"

Animal::Animal() : _type("default") 
{
  std::cout << GREEN << "Animal " << _type << " constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
  std::cout << GREEN << "Animal " << _type << " constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &cpy) 
{
  std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
  *this = cpy;
}

Animal &Animal::operator=(const Animal &cpy) 
{
  std::cout << GREEN << "Animal assignment operator called" << RESET
            << std::endl;
  if (this != &cpy)
  {
    this->_type = cpy._type;
  }
  return *this;
}

Animal::~Animal() 
{
  std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

void Animal::makeSound() const 
{
  std::cout << "* ... *" << std::endl;
}

std::string Animal::getType() const 
{
  return this->_type;
}