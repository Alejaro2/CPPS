#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
  std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
  this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
  std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete this->_brain;
}

void Dog::makeSound() const { std::cout << "Woof! Woof!" << std::endl; }

void Dog::setIdea(int index, std::string idea) {
  this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
  return this->_brain->getIdea(index);
}
