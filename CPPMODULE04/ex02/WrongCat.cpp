
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << GREEN << "WrongCat " << _type << " has been constructed!"
            << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat assignment operator called" << std::endl;
  if (this != &other)
    WrongAnimal::operator=(other);
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "WrongMeow! WrongMeow!" << std::endl;
}
