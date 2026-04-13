#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << GREEN << "WrongCat copy constructor called" << RESET
            << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat assignment operator called" << std::endl;
  if (this != &other)
    WrongAnimal::operator=(other);
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "WrongMeow! WrongMeow!" << std::endl;
}
