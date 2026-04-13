#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
  std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) 
{
  std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &other)
    Animal::operator=(other);
  return *this;
}

Cat::~Cat() 
{
  std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const 
{
  std::cout << "Meow! Meow!" << std::endl;
}
