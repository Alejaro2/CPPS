#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
  std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
  std::cout << GREEN << "WrongAnimal copy constructor called" << RESET
            << std::endl;
  *this = cpy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy) {
  std::cout << GREEN << "WrongAnimal assignment operator called" << RESET
            << std::endl;
  if (this != &cpy) {
    this->_type = cpy._type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const { std::cout << "* ... *" << std::endl; }

std::string WrongAnimal::getType() const { return this->_type; }
