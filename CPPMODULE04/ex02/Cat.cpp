#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") 
{
  std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
  this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other), _brain(new Brain(*other._brain)) 
{
  std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &other) 
  {
    AAnimal::operator=(other);
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
  }
  return *this;
}

Cat::~Cat() 
{
  std::cout << "Cat destructor called" << std::endl;
  delete this->_brain;
}

void Cat::makeSound() const 
{
  std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, std::string idea) 
{
  this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const 
{
  return this->_brain->getIdea(index);
}
