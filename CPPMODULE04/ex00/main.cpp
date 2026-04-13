#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
  const Animal *a = new Animal();
  const Animal *d = new Dog();
  const Animal *c = new Cat();

  std::cout << d->getType() << std::endl;
  std::cout << c->getType() << std::endl;

  d->makeSound();
  c->makeSound();
  a->makeSound();

  delete a;
  delete d;
  delete c;

  const WrongAnimal *wa = new WrongAnimal();
  const WrongAnimal *wc = new WrongCat();

  std::cout << wc->getType() << std::endl;

  wc->makeSound();
  wa->makeSound();

  delete wa;
  delete wc;

  return 0;
}
