#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
  std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) 
{
  std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &other)
    Animal::operator=(other);
  return *this;
}

Dog::~Dog() 
{
  std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const 
{
  std::cout << "Woof! Woof!" << std::endl; 
}
