#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
  std::cout << GREEN << "WrongAnimal " << _type << " has been constructed!"
            << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << GREEN << "WrongAnimal " << _type << " has been constructed!"
            << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
  std::cout << GREEN << "WrongAnimal " << _type << " has been copied!" << RESET
            << std::endl;
  *this = cpy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy) {
  std::cout << GREEN << "WrongAnimal " << _type << " has been assigned!"
            << RESET << std::endl;
  if (this != &cpy) {
    this->_type = cpy._type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << RED << "WrongAnimal " << _type << " has been destroyed!" << RESET
            << std::endl;
}

void WrongAnimal::makeSound() const { std::cout << "* ... *" << std::endl; }

std::string WrongAnimal::getType() const { return this->_type; }
